/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Object.cpp
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



#include "Object.hpp"



namespace fs = boost::filesystem;
namespace mep = sc::ManifestEntryParams;
namespace op = sc::ObjectParams;

namespace sc
{	
	Object::Object(const fs::path& newObjectPath, bool verboseOutput, bool newIsInitialization, op::Type newTypeForInitialization) : ManifestUser(newObjectPath / "objectManifest.json", ManifestDefinitions::ObjectManifest::rootEntry, ManifestDefinitions::ObjectManifest::rootEntryValueBase, newIsInitialization)
	{
		loadFromPath(newObjectPath, verboseOutput, newTypeForInitialization);
	}
	
	void Object::loadFromPath(const fs::path& newObjectPath, bool verboseOutput, op::Type newTypeForInitialization)
	{
		using namespace rapidjson;
		
		objectPath = newObjectPath;
		typeForInitialization = newTypeForInitialization;
		Utilities::validateFile(objectPath, fs::file_type::directory_file);
		loadManifestInternal(this, verboseOutput);
		
		if(getType() == op::Type::Stage)
		{
			fs::path penLayerPath(objectPath / "penLayer/penLayer.png");
			if(isInitialization)
			{
				fs::create_directories(penLayerPath.parent_path());
				Utilities::writePlainPNGToFile(penLayerPath, 480, 360, 0, 0, 0, 0);
			}
			setPenLayer(std::make_shared<Costume>(penLayerPath));
		}
	}
	
	void Object::buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
	{
		using namespace rapidjson;
		
		Value valueBuffer;
		Value costumesArray(kArrayType), soundsArray(kArrayType);
		
		valDest.SetObject();
		valDest.AddMember("objName", Value(getName().c_str(), alloc), alloc);
		
		//add all sounds
		valDest.AddMember("sounds", soundsArray, alloc);
		for(auto s : sounds)
		{
			s->buildJSON(valueBuffer, alloc);
			valDest["sounds"].PushBack(valueBuffer, alloc);
		}
		
		//add all costumes
		valDest.AddMember("costumes", costumesArray, alloc);
		for(auto c : costumes)
		{
			c->buildJSON(valueBuffer, alloc);
			valDest["costumes"].PushBack(valueBuffer, alloc);
		}
		
		valDest.AddMember("currentCostumeIndex", getCurrentCostumeIndex(), alloc);
	}
	
	void Object::saveAndReload(bool verboseOutput)
	{
		saveAndReloadInternal(this, verboseOutput);
	}
	
	void Object::reset()
	{
		ManifestUser::reset();
		costumes.clear();
		sounds.clear();
		scripts = nullptr;
		currentlyProcessedCostume = nullptr;
		currentlyProcessedSound = nullptr;
	}
	
	
	
	
	
	const fs::path& Object::getObjectPath()
	{
		return objectPath;
	}
	
	op::Type Object::getType()
	{
		return op::jsonStringToType(manifest["type"].GetString());
	}
	
	std::string Object::getName()
	{
		return manifest["objectName"].GetString();
	}
	
	int Object::getCurrentCostumeIndex()
	{
		return manifest["currentCostumeIndex"].GetInt();
	}
	
	std::shared_ptr<Costume> Object::getPenLayer()
	{
		if(getType() != op::Type::Stage)
			throw GeneralException("object '" + getName() + "' is not of type '" + op::typeToReadableString(getType()) + "', thus it does not have a pen layer");
		return penLayer;
	}
	
	std::vector<std::shared_ptr<Costume>>& Object::getCostumes()
	{
		return costumes;
	}
	
	std::vector<std::shared_ptr<Sound>>& Object::getSounds()
	{
		return sounds;
	}
	
	void Object::setType(op::Type newType)
	{
		manifest["type"].SetString(op::typeToJSONString(newType).c_str(), manifest.GetAllocator());
	}
	
	void Object::setName(const std::string& newName)
	{
		//Utilities::validateIdentifier("object name", newName);
		manifest["objectName"].SetString(newName.c_str(), manifest.GetAllocator());
	}
	
	void Object::setCurrentCostumeIndex(int newCurrentCostumeIndex)
	{
		if(newCurrentCostumeIndex < 0  ||  newCurrentCostumeIndex >= (int)costumes.size())
			throw GeneralException("costume index '" + std::to_string(newCurrentCostumeIndex) + "' is out of range (" + std::to_string(costumes.size()) + " costumes available)");
		manifest["currentCostumeIndex"].SetInt(newCurrentCostumeIndex);
	}
	
	void Object::setPenLayer(std::shared_ptr<Costume> newPenLayer)
	{
		if(getType() != op::Type::Stage)
			throw GeneralException("object '" + getName() + "' is not of type '" + op::typeToReadableString(getType()) + "', thus no pen layer may be assigned to it");
		penLayer = newPenLayer;
	}
	
	void Object::addCostume(std::shared_ptr<Costume> newCostume)
	{
		costumes.push_back(newCostume);
	}
	
	void Object::addSound(std::shared_ptr<Sound> newSound)
	{
		sounds.push_back(newSound);
	}
	
	
	
	
	
	op::Type Object::getTypeForInitialization()
	{
		return typeForInitialization;
	}
	
	std::shared_ptr<Costume> Object::getCurrentlyProcessedCostume()
	{
		return currentlyProcessedCostume;
	}
	
	std::shared_ptr<Sound> Object::getCurrentlyProcessedSound()
	{
		return currentlyProcessedSound;
	}
	
	void Object::setCurrentlyProcessedCostume(std::shared_ptr<Costume> newCurrentlyProcessedCostume)
	{
		currentlyProcessedCostume = newCurrentlyProcessedCostume;
	}
	
	void Object::setCurrentlyProcessedSound(std::shared_ptr<Sound> newCurrentlyProcessedSound)
	{
		currentlyProcessedSound = newCurrentlyProcessedSound;
	}
}
