/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ManifestEntryValue.hpp
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



#include <vector>
#include <rapidjson/document.h>

#include "ManifestEntry.hpp"
#include "ManifestEntryParams.hpp"
#include "ManifestStructure.hpp"
#include "GeneralException.hpp"



namespace sc
{
	namespace mep = ManifestEntryParams;
	
	template<typename T>
	class ManifestEntry;
	
	template<typename T>
	class ManifestEntryValue
	{
		public:
			std::string											attrName;
			bool												isRoot;
			mep::Type											type;
			mep::Importance										importance;
			bool												conditionResult;									//the condition result is set in ManifestStructure::validateJSON. Note that "false" generally has priority, i.e. if an Object's condition was false, all its children's conditions will be assumed to be "false" as well. Initially, all condition results are true
			T													value;
			std::vector<ManifestEntryValue<T>>					children;
			
			ManifestEntryValue() : isRoot(false), type(mep::Type::Invalid), importance(mep::Importance::Invalid), value(T()) { }
			ManifestEntryValue(mep::Type newType, mep::Importance newImportance, const std::vector<ManifestEntryValue<T>>& newChildren) : isRoot(false), type(newType), importance(newImportance), value(T()), children(newChildren) { }
			
			template<typename U>
			ManifestEntryValue(const ManifestEntry<U>& original)													//the resulting "ManifestEntryValue" will contain EVERY member of "original", INDEPENDENT from its condition result
			{
				attrName = original.attrName;
				isRoot = original.isRoot;
				type = original.type;
				importance = original.importance;
				conditionResult = true;
				value = T();
				
				std::vector<ManifestEntryValue<T>> newChildren;
				if(type == mep::Type::Array  ||  type == mep::Type::Object)
					for(auto& c : original.children.entries)
						newChildren.push_back(ManifestEntryValue<T>(c));
				if(type == mep::Type::Object)
					children.insert(children.begin(), newChildren.begin(), newChildren.end());
				else if(type == mep::Type::Array)
					children.push_back(ManifestEntryValue<T>(mep::Type::Object, importance, newChildren));			//note that an Array can only contain Objects. Here, a SINGLE instance of all objects is saved. This makes the function "addArrayEntry" much more comfortable
			}
			
			/*template<typename U>
			void assignConditionResults(U* targetInstance, const ManifestEntry<U>& currEntry)
			{
				if(currEntry.type != mep::Type::Object)
					throw GeneralException("cannot assign condition results using manifest entry non-object");
				
				for(ManifestEntry<bool>& e : currPredefinedValues.children.entries)
				{
					
				
					//the condition (initially evaluated in ManifestStructure::validateJSON) also applies here, because when it has been previously false, one cannot expect the "currValue" has the specified member
					if(!e.conditionResult)
						continue;
				
					//here are quite some places for inconsistencies to happen... (but if no bugs are there, these are impossible)
					if(!currValue.HasMember(e.attrName.c_str()))
						throw GeneralException("inconsistency detected while trying to purge manifest entries (member '" + e.attrName + "' is missing)");
			
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
								throw GeneralException("inconsistency detected while trying to purge manifest entries (member '" + e.attrName + "' is not an array, although it is supposed to)");
							for(Value::ValueIterator it = currArr.Begin(); it != currArr.End(); ++it)
								purgeNonPredefinedManifestEntries(*it, e.children[it - currArr.Begin()]);
						}
					}
					else
						currValue.RemoveMember(e.attrName.c_str());
				}
			}*/
			
			typename std::vector<ManifestEntryValue<T>>::iterator getEntryIterator(const std::string& name)
			{
				return std::find_if(children.begin(), children.end(), [&](const ManifestEntryValue<T>& entry) { return (entry.attrName == name); });
			}
			
			bool hasEntry(const std::string& name)
			{
				return (getEntryIterator(name) != children.end());
			}
			
			ManifestEntryValue<T>& getEntry(const std::string& name)
			{
				if(type != mep::Type::Object)
					throw GeneralException("manifest entry value is not an object, thus it cannot contain any entry named '" + name + "'");
				auto it = getEntryIterator(name);
				if(it == children.end())
					throw GeneralException("manifest entry value does not contain any entry named '" + name + "'");
				return *it;
			}
			
			void addArrayEntry(const T& newValue)
			{
				if(type != mep::Type::Array)
					throw GeneralException("manifest entry value is not an array");
				children.push_back(children.back());
				children.back().resetAll(newValue);
			}
			
			void resetAll(const T& newValue)
			{
				value = newValue;
				if(type == mep::Type::Array  ||  type == mep::Type::Object)
				{
					if(type == mep::Type::Array)
						children.resize(1);
					for(auto& c : children)
						c.resetAll(newValue);
				}
			}
	};
}
