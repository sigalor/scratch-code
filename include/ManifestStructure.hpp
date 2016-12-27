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
#include <algorithm>
#include <boost/filesystem.hpp>
#include <rapidjson/document.h>

#include "ManifestEntryParams.hpp"
#include "ManifestEntry.hpp"
#include "ManifestEntryValue.hpp"
#include "Utilities.hpp"
#include "GeneralException.hpp"



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
			
			const ManifestEntry<T>& getEntry(const std::string& name) const
			{
				auto it = std::find_if(entries.begin(), entries.end(), [&](const ManifestEntry<T>& entry) { return (entry.attrName == name); });
				if(it == entries.end())
					throw GeneralException("manifest structure does not contain any entry named '" + name + "'");
				return *it;
			}
			
			template<typename U>
			void validateJSON(T* targetInstance, rapidjson::Value& manifestJSON, rapidjson::Document::AllocatorType& alloc, const ManifestStructure& manifestStructure, const boost::filesystem::path& filepath, ManifestEntryValue<U>& currEntryValue, const U& defaultEntryValue, const U& triggeredEntryValue, bool verboseOutput=true, const std::string& parentHierarchy="root") const
			{
				using namespace rapidjson;
				namespace fs = boost::filesystem;
				namespace mep = ManifestEntryParams;
				
				std::string			warningMissingPrefix, currMemberLocation;
				mep::TypeVariant	currVal;
				
				//can only process objects
				if(!manifestJSON.IsObject())
					throw GeneralException("cannot validate JSON non-object");
				if(currEntryValue.type != mep::Type::Object)
					throw GeneralException("cannot fill manifest entry value non-object");
				
				//loop through all entries
				for(auto& e : manifestStructure.entries)
				{
					//set the current member's location as a string for showing it to the user (when that is necessary)
					currMemberLocation = parentHierarchy=="root" ? e.attrName : (parentHierarchy + "." + e.attrName);
					
					//if no condition is given, assume it is true. Just when the condition function returns 'false' or throws, ignore the current manifest entry
					if(e.condition)
					{
						try
							{ if(!e.condition(targetInstance)) continue; }
						catch(const GeneralException& e)
							{ continue; }
					}
					
					//set the current manifest entry value object to the current member and trigger it only if that member actually exists in the manifest before any processing
					ManifestEntryValue<U>& newCurrEntryValue = currEntryValue.getEntry(e.attrName);
					if(manifestJSON.HasMember(e.attrName.c_str()))
						newCurrEntryValue.value = triggeredEntryValue;
					
					//pre-processing takes place at the very beginning
					Utilities::safeWorker("unable to pre-process member '" + currMemberLocation + "'", e.preProcessor, targetInstance);
					
					//if the current member is not given or has a wrong time, try to find an alternative
					if(!manifestJSON.HasMember(e.attrName.c_str())  ||  !e.checkType(manifestJSON[e.attrName.c_str()]))
					{
						//if the member is required and it does not exist, the manifest is malformed
						if(e.importance == mep::Importance::Required)
							throw GeneralException("missing " + mep::typeToString(e.type) + " member '" + currMemberLocation + "'");
						
						warningMissingPrefix = "warning: in manifest at '" + fs::relative(filepath).string() + "': missing " + mep::typeToString(e.type) + " member '" + currMemberLocation + "'";
						if(e.type == mep::Type::Array  ||  e.type == mep::Type::Object)
						{
							//arrays and objects do not have an alternative value, they just become empty
							if(verboseOutput  &&  e.importance == mep::Importance::OptionalWithWarning)
								std::cerr << warningMissingPrefix << ", defaulting to empty " << mep::typeToString(e.type) << std::endl;
							if(manifestJSON.HasMember(e.attrName.c_str()))
								manifestJSON.RemoveMember(e.attrName.c_str());
							Value emptyCompoundVal(e.type==mep::Type::Array ? kArrayType : kObjectType);
							manifestJSON.AddMember(Value(e.attrName.c_str(), alloc), emptyCompoundVal, alloc);
						}
						else
						{
							//the alternative function will return a replacement value for the missing member
							if(!e.alternative)
								throw GeneralException("alternative function not set for member '" + currMemberLocation + "'");
							currVal = Utilities::safeWorker("unable to obtain alternative for member '" + currMemberLocation + "'", e.alternative, targetInstance);
							
							//output a warning message if that is desired
							if(verboseOutput  &&  e.importance == mep::Importance::OptionalWithWarning)
								std::cerr << warningMissingPrefix << ", defaulting value to '" << currVal << "'" << std::endl;
							
							//remove the member if it existed but had the wrong time, then set its value to the generated alternative
							if(manifestJSON.HasMember(e.attrName.c_str()))
								manifestJSON.RemoveMember(e.attrName.c_str());
							switch(e.type)
							{
								case mep::Type::Integer	: manifestJSON.AddMember(Value(e.attrName.c_str(), alloc), Value(boost::get<int>(currVal)), alloc); break;
								case mep::Type::String	: manifestJSON.AddMember(Value(e.attrName.c_str(), alloc), Value(boost::get<std::string>(currVal).c_str(), alloc), alloc); break;
								default					: throw GeneralException("cannot set JSON value for " + mep::typeToString(e.type));
							}
						}
					}
					
					if(e.type == mep::Type::Array)
					{
						Value& currArr = manifestJSON[e.attrName.c_str()];
						for(Value::ValueIterator it = currArr.Begin(); it != currArr.End(); ++it)
						{
							auto i = it - currArr.Begin();
							if(it != currArr.Begin())
								newCurrEntryValue.addArrayEntry(defaultEntryValue);
							std::string arrayDesc(e.attrName + "[" + std::to_string(i) + "]");
							std::string currArrayElementLocation(parentHierarchy=="root" ? arrayDesc : (parentHierarchy + "." + arrayDesc));
							Utilities::safeWorker("unable to pre-process array member '" + currArrayElementLocation + "'", e.elementPreProcessor, targetInstance);
							validateJSON(targetInstance, *it, alloc, e.children, filepath, newCurrEntryValue.children[i], defaultEntryValue, triggeredEntryValue, verboseOutput, currArrayElementLocation);
							Utilities::safeWorker("unable to post-process array member '" + currArrayElementLocation + "'", e.elementPostProcessor, targetInstance);
						}
					}
					else if(e.type == mep::Type::Object)
					{
						std::string currObjectLocation(parentHierarchy=="root" ? e.attrName : (parentHierarchy + "." + e.attrName));
						Utilities::safeWorker("unable to pre-process object '" + currObjectLocation + "'", e.elementPreProcessor, targetInstance);
						validateJSON(targetInstance, manifestJSON[e.attrName.c_str()], alloc, e.children, filepath, newCurrEntryValue, defaultEntryValue, triggeredEntryValue, verboseOutput, currObjectLocation);
						Utilities::safeWorker("unable to post-process object '" + currObjectLocation + "'", e.elementPostProcessor, targetInstance);
					}
					else
					{
						switch(e.type)
						{
							case mep::Type::Integer	: currVal = manifestJSON[e.attrName.c_str()].GetInt(); break;
							case mep::Type::String	: currVal = manifestJSON[e.attrName.c_str()].GetString(); break;
							default									: break;
						}
						Utilities::safeWorker("unable to process member '" + currMemberLocation + "'", e.processor, targetInstance, currVal);
					}
					
					if(e.postProcessor)
						Utilities::safeWorker("unable to post-process member '" + currMemberLocation + "'", e.postProcessor, targetInstance);
				}
			}
			
			template<typename U>
			void validateJSON(T* targetInstance, const boost::filesystem::path& filepath, rapidjson::Document& doc, ManifestEntryValue<U>& currEntryValue, const U& defaultEntryValue, const U& triggeredEntryValue, bool verboseOutput=true) const
			{
				Utilities::readDocumentFromFile(filepath, doc);
				try
					{ validateJSON(targetInstance, doc, doc.GetAllocator(), *this, filepath, currEntryValue, defaultEntryValue, triggeredEntryValue, verboseOutput); }
				catch(const GeneralException& e)
					{ throw GeneralException("in manifest at '" + boost::filesystem::relative(filepath).string() + "': " + e.what()); }
			}
	};
}
