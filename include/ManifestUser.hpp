/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ManifestUser.hpp
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

#include "ManifestEntry.hpp"
#include "ManifestEntryValue.hpp"
#include "ManifestEntryParams.hpp"
#include "Utilities.hpp"



namespace sc
{
	template<typename T>
	class ManifestUser
	{
		protected:
			boost::filesystem::path								manifestPath;
			rapidjson::Document									manifest;
			const ManifestEntry<T>&								rootEntryRef;
			ManifestEntryValue<bool>							predefinedValues;
			bool												isInitialization;
			
			ManifestUser(const boost::filesystem::path& newManifestPath, const ManifestEntry<T>& newRootEntryRef, const ManifestEntryValue<bool>& newPredefinedValues, bool newIsInitialization=false) : manifestPath(newManifestPath), rootEntryRef(newRootEntryRef), predefinedValues(newPredefinedValues), isInitialization(newIsInitialization)
			{
				//empty
			}
			
			virtual void reset()
			{
				manifest.SetObject();
				predefinedValues.resetAll(false);
				isInitialization = false;
			}
			
			void loadManifestInternal(T* targetInstance, bool verboseOutput=true)									//parameter 1 implies that "loadManifestInternal" can only be called from another class that derived like this: "class OtherClass : public ManifestUser<OtherClass> { ... }"
			{
				try
				{
					if(isInitialization  &&  !boost::filesystem::exists(manifestPath))								//if the initialization is happening, the file at "manifestPath" may need to be created; do this with an empty JSON object
						Utilities::createFile(manifestPath, "{}");													//this implies that NO ManifestEntries in the definition's first level are allowed to have "mep::Importance::Required"!
					rootEntryRef.children.validateJSON(targetInstance, manifestPath, manifest, predefinedValues, false, true, verboseOutput);
				}
				catch(const boost::filesystem::filesystem_error& e)
					{ throw GeneralException(std::string("file system error: ") + e.what()); }
			}
			
			void saveAndReloadInternal(T* targetInstance, bool verboseOutput=true)									//same like "loadManifestInternal"
			{
				purgeNonPredefinedManifestEntries(manifest, predefinedValues);
				Utilities::writeDocumentToFile(manifestPath, manifest);
				reset();
				loadManifestInternal(targetInstance, verboseOutput);
			}
			
			void purgeNonPredefinedManifestEntries(rapidjson::Value& currValue, ManifestEntryValue<bool>& currPredefinedValues)			//purges all entries from the "manifest" object that were not there when the manifest was loaded
			{
				using namespace rapidjson;
	
				if(!currValue.IsObject())
					throw GeneralException("cannot purge manifest entries in JSON non-object");
				if(currPredefinedValues.type != mep::Type::Object)
					throw GeneralException("cannot purge manifest entries using manifest entry value non-object");
		
				for(ManifestEntryValue<bool>& e : currPredefinedValues.children)
				{
					//here are quite some places for inconsistencies to happen... (but if no bugs are there, these are impossible)
					if(!currValue.HasMember(e.attrName.c_str()))
						throw GeneralException("inconsistency detected while trying to purge manifest entries");
			
					//if the "value" member is false, the current manifest entry can definitely be removed. If it's not, arrays and objects need to processed recursively
					//if currently the initialization is happening, only remove members that have an importance lower than or equal to "Optional"
					if(e.value  ||  (isInitialization  &&  (e.importance == mep::Importance::Required  ||  e.importance == mep::Importance::OptionalWithWarning)))
					{
						if(e.type == mep::Type::Object)
							purgeNonPredefinedManifestEntries(currValue[e.attrName.c_str()], e);
						else if(e.type == mep::Type::Array)
						{
							Value& currArr = currValue[e.attrName.c_str()];
							if(!currArr.IsArray())
								throw GeneralException("inconsistency detected while trying to purge manifest entries");
							for(Value::ValueIterator it = currArr.Begin(); it != currArr.End(); ++it)
								purgeNonPredefinedManifestEntries(*it, e.children[it - currArr.Begin()]);
						}
					}
					else
						currValue.RemoveMember(e.attrName.c_str());
				}
			}
		
		public:
			const boost::filesystem::path& getManifestPath()
			{
				return manifestPath;
			}
			
			rapidjson::Document& getManifest()
			{
				return manifest;
			}
			
			ManifestEntryValue<bool>& getPredefinedValues()
			{
				return predefinedValues;
			}
			
			bool getIsInitialization()
			{
				return isInitialization;
			}
	};
}
