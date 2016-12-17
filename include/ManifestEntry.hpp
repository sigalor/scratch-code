/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ManifestEntry.hpp
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
#include <functional>

#include <boost/variant.hpp>
#include <rapidjson/document.h>

#include "ManifestStructure.hpp"



namespace sc
{
	template<typename T>
	class ManifestStructure;

	namespace ManifestEntryParams
	{
		enum class Type
		{
			Integer,
			String,
			Array,
			Object
		};
		
		enum class Importance
		{
			Required,
			OptionalWithWarning,
			Optional
		};
		
		using TypeVariant = boost::variant<int, std::string>;
	}

	template<typename T>
	class ManifestEntry
	{
		public:
			using GeneratorFunction = std::function<ManifestEntryParams::TypeVariant(T*)>;
			using ProcessorFunction = std::function<void(T*, const ManifestEntryParams::TypeVariant&)>;
			
			std::string											attrName;
			ManifestEntryParams::Type							type;
			ManifestEntryParams::Importance						importance;
			GeneratorFunction									alternative;										//only for Type::Integer and Type::String
			ProcessorFunction									processor;											//like 'alternative'
			ManifestStructure<T>								children;											//only for Type::Array and Type::Object

			ManifestEntry(const std::string& newAttrName, ManifestEntryParams::Type newType, ManifestEntryParams::Importance newImportance, const GeneratorFunction& newAlternative, const ProcessorFunction& newProcessor) : attrName(newAttrName), type(newType), importance(newImportance), alternative(newAlternative), processor(newProcessor), children({})
			{
				//for Importance::Required
			}
			
			ManifestEntry(const std::string& newAttrName, ManifestEntryParams::Type newType, const ProcessorFunction& newProcessor) : attrName(newAttrName), type(newType), importance(ManifestEntryParams::Importance::Required), processor(newProcessor), children({})
			{
				//for Importance::OptionalWithWarning or Importance::Optional
			}
			
			ManifestEntry(const std::string& newAttrName, ManifestEntryParams::Type newType, ManifestEntryParams::Importance newImportance, const ManifestStructure<T>& newChildren) : attrName(newAttrName), type(newType), importance(newImportance), children(newChildren)
			{
				//for Type::Array or Type::Object
			}
	};
}
