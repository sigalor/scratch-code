/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Object.hpp
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
#include <memory>
#include <tuple>

#include <boost/filesystem.hpp>
#include <boost/variant.hpp>
#include <rapidjson/document.h>
#include <ast/AST.hpp>

#include "Costume.hpp"
#include "Sound.hpp"
#include "ManifestStructure.hpp"
#include "Utilities.hpp"



namespace sc
{
	class Object
	{
		public:
			enum class Type
			{
				Invalid,
				Stage,
				Generic
			};
			
			static const std::string							typeToString(Type type);
	
			static const std::vector<std::string>				allowedCostumeExts, allowedScriptExts, allowedSoundExts;
			static const ManifestStructure<Object>				manifestStructure;
		
		private:			
			boost::filesystem::path								objectPath;
			rapidjson::Document									manifest;
			std::shared_ptr<Costume>							penLayer;											//only needed when getType()==Type::Stage
			std::vector<std::shared_ptr<Costume>>				costumes;
			std::vector<std::shared_ptr<Sound>>					sounds;
			std::shared_ptr<ast::StatementList>					scripts;
			
			bool												isInitialization;
			Type												typeForInitialization;
			std::shared_ptr<Costume>							currentlyProcessedCostume;							//both only needed during manifest loading
			std::shared_ptr<Sound>								currentlyProcessedSound;
	
		public:
			Object();
			Object(const boost::filesystem::path& newObjectPath, bool verboseOutput=true, bool isInitialization=false, Type newTypeForInitialization=Type::Generic);
			
			void												loadFromPath(const boost::filesystem::path& newObjectPath, bool verboseOutput=true, bool isInitialization=false, Type newTypeForInitialization=Type::Generic);
			void												buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
			void												saveAndReload(bool verboseOutput=true);
			
			Type												getType();
			const boost::filesystem::path&						getObjectPath();
			std::string											getName();
			rapidjson::Document&								getManifest();
			int													getCurrentCostumeIndex();
			std::shared_ptr<Costume>							getPenLayer();
			std::vector<std::shared_ptr<Costume>>&				getCostumes();
			std::vector<std::shared_ptr<Sound>>&				getSounds();
			void												setType(Type newType);
			void												setName(const std::string& newName);
			void												setCurrentCostumeIndex(int newCurrentCostumeIndex);
			void												setPenLayer(std::shared_ptr<Costume> newPenLayer);
			void												addCostume(std::shared_ptr<Costume> newCostume);
			void												addSound(std::shared_ptr<Sound> newSound);
			
			bool												getIsInitialization();
			Type												getTypeForInitialization();
			std::shared_ptr<Costume>							getCurrentlyProcessedCostume();
			std::shared_ptr<Sound>								getCurrentlyProcessedSound();
			void												setCurrentlyProcessedCostume(std::shared_ptr<Costume> newCurrentCostume);
			void												setCurrentlyProcessedSound(std::shared_ptr<Sound> newCurrentSound);
	};
}
