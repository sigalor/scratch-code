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



namespace sc
{
	namespace mep = ManifestEntryParams;
	
	template<typename T>
	class ManifestEntryValue
	{
		public:
			std::string											attrName;
			bool												isRoot;
			mep::Type											type;
			T													value;
			std::vector<ManifestEntryValue<T>>					children;
			
			ManifestEntryValue() : isRoot(false), type(mep::Type::Invalid), value(T()) { }
			ManifestEntryValue(mep::Type newType) : isRoot(false), type(newType), value(T()) { }
			ManifestEntryValue(mep::Type newType, const std::vector<ManifestEntryValue<T>>& newChildren) : isRoot(false), type(newType), value(T()), children(newChildren) { }
			
			template<typename U>
			ManifestEntryValue(const ManifestEntry<U>& original)
			{
				attrName = original.attrName;
				isRoot = original.isRoot;
				type = original.type;
				value = T();
				
				std::vector<ManifestEntryValue<T>> newChildren;
				if(type == mep::Type::Array  ||  type == mep::Type::Object)
					for(auto& c : original.children.entries)
						newChildren.push_back(ManifestEntryValue<T>(c));
				if(type == mep::Type::Object)
					children.insert(children.begin(), newChildren.begin(), newChildren.end());
				else if(type == mep::Type::Array)
					children.push_back(ManifestEntryValue<T>(mep::Type::Object, newChildren));
			}
			
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
