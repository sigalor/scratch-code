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

#include <boost/filesystem.hpp>
#include <boost/variant.hpp>
#include <rapidjson/document.h>
#include <ast/AST.hpp>

#include "Costume.hpp"
#include "Sound.hpp"
#include "ManifestStructure.hpp"



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
	
		private:
			static const std::vector<std::string>				allowedCostumeExts, allowedScriptExts, allowedSoundExts;
			static const ManifestStructure<Object>				manifestStructure;
			Type												type;
			boost::filesystem::path								objectPath;
			std::string											name;
			rapidjson::Document									manifest;
			std::vector<std::shared_ptr<Costume>>				costumes;
			std::vector<std::shared_ptr<Sound>>					sounds;
			//std::shared_ptr<ast::StatementList>					scripts;
			std::shared_ptr<Costume>							currentCostume;
			std::shared_ptr<Sound>								currentSound;
	
		public:
			Object();
			Object(const boost::filesystem::path& newObjectPath, bool verboseOutput=true);
			
			void												loadFromPath(const boost::filesystem::path& newObjectPath, bool verboseOutput=true);
			Type												getType();
			const boost::filesystem::path&						getObjectPath();
			const std::string&									getName();
			rapidjson::Document&								getManifest();
			std::vector<std::shared_ptr<Costume>>&				getCostumes();
			std::vector<std::shared_ptr<Sound>>&				getSounds();
			std::shared_ptr<Costume>							getCurrentCostume();
			std::shared_ptr<Sound>								getCurrentSound();
			void												setType(Type newType);
			void												setName(const std::string& newName);
			void												addCostume(std::shared_ptr<Costume> newCostume);
			void												addSound(std::shared_ptr<Sound> newSound);
	};
}
