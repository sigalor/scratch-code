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
#include <type_traits>

#include <boost/filesystem.hpp>
#include <boost/variant.hpp>
#include <rapidjson/document.h>
#include <ast/AST.hpp>

#include "Resource.hpp"
#include "Costume.hpp"
#include "Sound.hpp"
#include "ManifestEntry.hpp"
#include "ManifestEntryValue.hpp"
#include "ManifestEntryParams.hpp"
#include "ManifestUser.hpp"
#include "ManifestDefinitions.hpp"
#include "ObjectParams.hpp"
#include "Utilities.hpp"



namespace sc
{
	class Object : public ManifestUser<Object>
	{
		private:			
			boost::filesystem::path								objectPath;
			std::shared_ptr<Costume>							penLayer;											//only needed when getType()==Type::Stage
			std::vector<std::shared_ptr<Costume>>				costumes;
			std::vector<std::shared_ptr<Sound>>					sounds;
			std::shared_ptr<ast::StatementList>					scripts;
			
			ObjectParams::Type									typeForInitialization;
			std::shared_ptr<Costume>							currentlyProcessedCostume;							//both only needed during manifest loading
			std::shared_ptr<Sound>								currentlyProcessedSound;
			
		public:
			Object(const boost::filesystem::path& newObjectPath, bool verboseOutput=true, bool newIsInitialization=false, ObjectParams::Type newTypeForInitialization=ObjectParams::Type::Generic);
			
			void												loadFromPath(const boost::filesystem::path& newObjectPath, bool verboseOutput=true, ObjectParams::Type newTypeForInitialization=ObjectParams::Type::Generic);
			void												buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
			void												saveAndReload(bool verboseOutput=true);
			virtual void										reset();
			
			const boost::filesystem::path&						getObjectPath();
			std::string											getName();
			ObjectParams::Type									getType();
			boost::filesystem::path								getCostumesDirectoryPath();
			boost::filesystem::path								getScriptsDirectoryPath();
			boost::filesystem::path								getSoundsDirectoryPath();
			boost::filesystem::path								getPenLayerPath();
			int													getCurrentCostumeIndex();
			std::shared_ptr<Costume>							getPenLayer();
			std::vector<std::shared_ptr<Costume>>&				getCostumes();
			std::vector<std::shared_ptr<Sound>>&				getSounds();
			void												setName(const std::string& newName);
			void												setType(ObjectParams::Type newType);
			void												setCostumesDirectoryPath(const std::string& newCostumesDirectoryPath);
			void												setScriptsDirectoryPath(const std::string& newScriptsDirectoryPath);
			void												setSoundsDirectoryPath(const std::string& newSoundsDirectoryPath);
			void												setPenLayerPath(const std::string& newPenLayerPath);
			void												setCurrentCostumeIndex(int newCurrentCostumeIndex);
			void												setPenLayer(std::shared_ptr<Costume> newPenLayer);
			void												addCostume(std::shared_ptr<Costume> newCostume);
			void												addSound(std::shared_ptr<Sound> newSound);
			
			template<typename T>
			typename std::enable_if_t<std::is_base_of<Resource, T>::value>
			checkResourceNameUniqueness(const std::string& resourcePluralDesc, const std::vector<std::shared_ptr<T>>& resourceList)
			{
				if(resourceList.size() <= 1)
					return;
				for(auto it = resourceList.begin(); it != resourceList.end(); ++it)
				{
					auto otherResource = std::find_if(it + 1, resourceList.end(), [&](std::shared_ptr<T> resource)
						{ return (resource->getName() == (*it)->getName()); });
					if(otherResource != resourceList.end())
						throw GeneralException("object '" + getName() + "' may not contain two " + resourcePluralDesc + " with the same name: candidates are at '" + boost::filesystem::relative((*it)->getResourcePath()).string() + "' and '" + boost::filesystem::relative((*otherResource)->getResourcePath()).string() + "'");
				}
			}
			
			ObjectParams::Type									getTypeForInitialization();
			std::shared_ptr<Costume>							getCurrentlyProcessedCostume();
			std::shared_ptr<Sound>								getCurrentlyProcessedSound();
			void												setCurrentlyProcessedCostume(std::shared_ptr<Costume> newCurrentCostume);
			void												setCurrentlyProcessedSound(std::shared_ptr<Sound> newCurrentSound);
	};
}
