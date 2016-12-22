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
#include <tuple>

#include <rapidjson/document.h>

#include "ManifestEntryParams.hpp"
#include "ManifestStructure.hpp"



namespace mep = sc::ManifestEntryParams;

namespace sc
{
	template<typename T>
	class ManifestStructure;

	template<typename T>
	class ManifestEntry
	{
		public:
			using ConditionFunction = std::function<bool(T*)>;
			using PreProcessingFunction = std::function<void(T*)>;
			using ElementPreProcessingFunction = std::function<void(T*)>;
			using AlternativeFunction = std::function<mep::TypeVariant(T*)>;
			using ProcessingFunction = std::function<void(T*, const mep::TypeVariant&)>;
			using ElementPostProcessingFunction = std::function<void(T*)>;
			using PostProcessingFunction = std::function<void(T*)>;
			using FunctionsTuple = std::tuple<ConditionFunction, AlternativeFunction, ProcessingFunction>;
			using ArrayFunctionsTuple = std::tuple<ConditionFunction, PreProcessingFunction, ElementPreProcessingFunction, ElementPostProcessingFunction, PostProcessingFunction>;
			
			std::string											attrName;
			mep::Type											type;
			mep::Importance										importance;
			ConditionFunction									condition;
			PreProcessingFunction								preProcessor;
			ElementPreProcessingFunction						elementPreProcessor;
			AlternativeFunction									alternative;										//only for Type::Integer and Type::String
			ProcessingFunction									processor;											//like 'alternative'
			ElementPostProcessingFunction						elementPostProcessor;
			PostProcessingFunction								postProcessor;
			ManifestStructure<T>								children;											//only for Type::Array
			
			/*
			ManifestEntry(const std::string& newAttrName, mep::Type newType, mep::Importance newImportance, const AlternativeFunction& newAlternative, const ProcessingFunction& newProcessor) : attrName(newAttrName), type(newType), importance(newImportance), alternative(newAlternative), processor(newProcessor), children({}) { }			//for Importance::Required
			ManifestEntry(const std::string& newAttrName, mep::Type newType, const ProcessingFunction& newProcessor) : attrName(newAttrName), type(newType), importance(mep::Importance::Required), processor(newProcessor), children({}) { }																										//for Importance::OptionalWithWarning or Importance::Optional
			ManifestEntry(const std::string& newAttrName, mep::Type newType, mep::Importance newImportance, const ManifestStructure<T>& newChildren) : attrName(newAttrName), type(newType), importance(newImportance), children(newChildren) { }																									//for Type::Array
			ManifestEntry(const std::string& newAttrName, mep::Type newType, mep::Importance newImportance, const PreProcessingFunction& newPreProcessor, const ManifestStructure<T>& newChildren) : attrName(newAttrName), type(newType), importance(newImportance), preProcessor(newPreProcessor), children(newChildren) { }						//for Type::Array, preparer is called for every array member
			*/
			
			//constructor for other types
			ManifestEntry(const std::string& newAttrName, mep::Type newType, mep::Importance newImportance, const FunctionsTuple& functions)
				 :	attrName(newAttrName),
				 	type(newType),
				 	importance(newImportance),
				 	condition(std::get<0>(functions)),
				 	alternative(std::get<1>(functions)),
				 	processor(std::get<2>(functions)),
				 	children({}) { }
			
			//constructor for mep::Type::Array
			ManifestEntry(const std::string& newAttrName, mep::Type newType, mep::Importance newImportance, const ArrayFunctionsTuple& arrayFunctions, const ManifestStructure<T>& newChildren)
				 :	attrName(newAttrName),
				 	type(newType),
				 	importance(newImportance),
				 	condition(std::get<0>(arrayFunctions)),
				 	preProcessor(std::get<1>(arrayFunctions)),
				 	elementPreProcessor(std::get<2>(arrayFunctions)),
				 	elementPostProcessor(std::get<3>(arrayFunctions)),
				 	postProcessor(std::get<4>(arrayFunctions)),
				 	children(newChildren) { }
			
			bool checkType(rapidjson::Value& val) const
			{
				switch(type)
				{
					case mep::Type::Integer	: return val.IsInt();
					case mep::Type::String	: return val.IsString();
					case mep::Type::Array	: return val.IsArray();
					default					: return false;
				}
			}
	};
}