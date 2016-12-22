/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ManifestStructure.hpp
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



#pragma once



#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <rapidjson/document.h>

#include "ManifestEntryParams.hpp"
#include "ManifestEntry.hpp"
#include "Utilities.hpp"
#include "GeneralException.hpp"



namespace fs = boost::filesystem;

namespace sc
{
	template<typename T>
	class ManifestStructure
	{
		public:
			std::vector<ManifestEntry<T>>						entries;
			
			ManifestStructure(const std::vector<ManifestEntry<T>>& newEntries) : entries(newEntries)
			{
				//empty
			}
			
			void validateJSON(T* targetInstance, rapidjson::Value& manifestJSON, rapidjson::Document::AllocatorType& alloc, const ManifestStructure& manifestStructure, const boost::filesystem::path& filepath, bool verboseOutput=true, const std::string& parentHierarchy="root") const
			{
				namespace fs = boost::filesystem;
				using namespace rapidjson;
				
				//get rapidjson allocator
				std::string							warningMissingPrefix, currMemberLocation;
				ManifestEntryParams::TypeVariant	currVal;
				
				//can only process objects
				if(!manifestJSON.IsObject())
					throw GeneralException("cannot validate JSON non-object");
				
				//loop through all entries
				for(auto& e : manifestStructure.entries)
				{
					currMemberLocation = parentHierarchy=="root" ? e.attrName : (parentHierarchy + "." + e.attrName);
					
					if(e.preProcessor)
					{
						try
							{ e.preProcessor(targetInstance); }
						catch(const GeneralException& e)
							{ throw GeneralException("unable to pre-process member '" + currMemberLocation + "': " + e.what()); }
					}
					
					if(!manifestJSON.HasMember(e.attrName.c_str())  ||  !e.checkType(manifestJSON[e.attrName.c_str()]))
					{
						if(e.importance == ManifestEntryParams::Importance::Required)
							throw GeneralException("missing " + ManifestEntryParams::typeToString(e.type) + " member '" + currMemberLocation + "'");
						
						warningMissingPrefix = "warning: in manifest at '" + fs::relative(filepath).string() + "': missing " + ManifestEntryParams::typeToString(e.type) + " member '" + currMemberLocation + "'";
						if(e.type == ManifestEntryParams::Type::Array)
						{
							if(verboseOutput  &&  e.importance == ManifestEntryParams::Importance::OptionalWithWarning)
								std::cerr << warningMissingPrefix << ", defaulting to empty array" << std::endl;
							if(manifestJSON.HasMember(e.attrName.c_str()))
								manifestJSON.RemoveMember(e.attrName.c_str());
							Value emptyArrayVal(kArrayType);
							manifestJSON.AddMember(Value(e.attrName.c_str(), alloc), emptyArrayVal, alloc);
						}
						else
						{
							if(!e.alternative)
								throw GeneralException("alternative function not set for member '" + currMemberLocation + "'");
							try
								{ currVal = e.alternative(targetInstance); }
							catch(const GeneralException& e)
								{ throw GeneralException("unable to obtain alternative for member '" + currMemberLocation + "': " + e.what()); }
							
							if(verboseOutput  &&  e.importance == ManifestEntryParams::Importance::OptionalWithWarning)
								std::cerr << warningMissingPrefix << ", defaulting value to '" << currVal << "'" << std::endl;
							if(manifestJSON.HasMember(e.attrName.c_str()))
								manifestJSON.RemoveMember(e.attrName.c_str());
						
							switch(e.type)
							{
								case ManifestEntryParams::Type::Integer	: manifestJSON.AddMember(Value(e.attrName.c_str(), alloc), Value(boost::get<int>(currVal)), alloc); break;
								case ManifestEntryParams::Type::String	: manifestJSON.AddMember(Value(e.attrName.c_str(), alloc), Value(boost::get<std::string>(currVal).c_str(), alloc), alloc); break;
								default									: throw GeneralException("cannot set JSON value for " + ManifestEntryParams::typeToString(e.type));
							}
						}
					}
					
					if(e.type == ManifestEntryParams::Type::Array)
					{
						Value& currArr = manifestJSON[e.attrName.c_str()];
						for(Value::ValueIterator it = currArr.Begin(); it != currArr.End(); ++it)
						{
							std::string arrayDesc(e.attrName + "[" + std::to_string(it-currArr.Begin()) + "]");
							std::string currArrayElementLocation(parentHierarchy=="root" ? arrayDesc : (parentHierarchy + "." + arrayDesc));
							if(e.elementPreProcessor)
							{
								try
									{ e.elementPreProcessor(targetInstance); }
								catch(const GeneralException& e)
									{ throw GeneralException("unable to pre-process array member '" + currArrayElementLocation + "': " + e.what()); }
							}
							validateJSON(targetInstance, *it, alloc, e.children, filepath, verboseOutput, currArrayElementLocation);
							if(e.elementPostProcessor)
							{
								try
									{ e.elementPostProcessor(targetInstance); }
								catch(const GeneralException& e)
									{ throw GeneralException("unable to post-process array member '" + currArrayElementLocation + "': " + e.what()); }
							}
						}
					}
					else
					{
						switch(e.type)
						{
							case ManifestEntryParams::Type::Integer	: currVal = manifestJSON[e.attrName.c_str()].GetInt(); break;
							case ManifestEntryParams::Type::String	: currVal = manifestJSON[e.attrName.c_str()].GetString(); break;
							default									: break;
						}
						if(e.processor)
						{
							try
								{ e.processor(targetInstance, currVal); }
							catch(const GeneralException& e)
								{ throw GeneralException("unable to process member '" + currMemberLocation + "': " + e.what()); }
						}
					}
					
					if(e.postProcessor)
					{
						try
							{ e.postProcessor(targetInstance); }
						catch(const GeneralException& e)
							{ throw GeneralException("unable to post-process member '" + currMemberLocation + "': " + e.what()); }
					}
				}
			}
			
			void validateJSON(T* targetInstance, const boost::filesystem::path& filepath, rapidjson::Document& doc, bool verboseOutput=true) const
			{
				Utilities::readDocumentFromFile(filepath, doc);
				try
					{ validateJSON(targetInstance, doc, doc.GetAllocator(), *this, filepath, verboseOutput); }
				catch(const GeneralException& e)
					{ throw GeneralException("in manifest at '" + fs::relative(filepath).string() + "': " + e.what()); }
			}
	};
}
