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

namespace sc
{
	const std::vector<std::string> Object::allowedCostumeExts	= { ".png" };
	const std::vector<std::string> Object::allowedScriptExts	= { ".sc" };
	const std::vector<std::string> Object::allowedSoundExts		= { ".wav" };
	
	const ManifestStructure<Object> Object::manifestStructure(
	{
		ManifestEntry<Object>
		{
			"objectName",
			ManifestEntryParams::Type::String,
			ManifestEntryParams::Importance::OptionalWithWarning,
			[](Object* obj) -> ManifestEntryParams::TypeVariant
			{
				return obj->getObjectPath().filename().string();
			},
			[](Object* obj, const ManifestEntryParams::TypeVariant& val)
			{
				obj->setName(boost::get<std::string>(val));
			}
		},
		ManifestEntry<Object>
		{
			"type",
			ManifestEntryParams::Type::String,
			ManifestEntryParams::Importance::OptionalWithWarning,
			[](Object* obj)
			{
				return "generic";
			},
			[](Object* obj, const ManifestEntryParams::TypeVariant& val)
			{
				std::string typeStr(boost::get<std::string>(val));
				if(typeStr == "stage")
					obj->setType(Object::Type::Stage);
				else if(typeStr == "generic")
					obj->setType(Object::Type::Generic);
				else
					throw GeneralException("'" + typeStr + "'");		//object manifest at '" + manifestPath.string() + "' contains invalid 'type' member: 
			}
		},
		ManifestEntry<Object>
		{
			"costumes",
			ManifestEntryParams::Type::Array,
			ManifestEntryParams::Importance::OptionalWithWarning,
			ManifestStructure<Object>(
			{
				ManifestEntry<Object>
				(
					"path",
					ManifestEntryParams::Type::String,
					[](Object* obj, const ManifestEntryParams::TypeVariant& val)
					{
						obj->getCurrentCostume()->loadFromPath(obj->getObjectPath() / "costumes" / boost::get<std::string>(val));
					}
				)
			})
		}
	});
	
	
	
	

	Object::Object() : type(Type::Invalid)
	{
	
	}
	
	Object::Object(const fs::path& newObjectPath, bool verboseOutput) : type(Type::Invalid)
	{
		loadFromPath(newObjectPath, verboseOutput);
	}
	
	void Object::loadFromPath(const fs::path& newObjectPath, bool verboseOutput)
	{
		using namespace rapidjson;
	
		objectPath = newObjectPath;
		Utilities::validateFile(objectPath, fs::file_type::directory_file);
		
		//load manifest
		Document::AllocatorType& alloc = manifest.GetAllocator();
		fs::path manifestPath(objectPath / "objectManifest.json");
		Utilities::readDocumentFromFile(manifestPath, manifest);
		
		//check and get object name
		if(!manifest.HasMember("objectName")  ||  !manifest["objectName"].IsString())
		{
			std::string altName(objectPath.filename().string());
			if(verboseOutput)
				std::cerr << "warning: object manifest at '" << manifestPath << "' is missing string member 'objectName', defaulting to '" << altName << "'" << std::endl;
			if(manifest.HasMember("objectName"))
				manifest.RemoveMember("objectName");
			manifest.AddMember("objectName", Value(altName.c_str(), alloc), alloc);
		}
		name = manifest["objectName"].GetString();
		Utilities::validateIdentifier("object name", name);
		
		//check and get type
		if(!manifest.HasMember("type")  ||  !manifest["type"].IsString())
		{
			if(verboseOutput)
				std::cerr << "warning: object manifest at '" << manifestPath << "' is missing string member 'type', defaulting to 'generic'" << std::endl;
			if(manifest.HasMember("type"))
				manifest.RemoveMember("type");
			manifest.AddMember("type", "generic", alloc);
		}
		std::string typeStr(manifest["type"].GetString());
		if(typeStr == "stage")
			type = Type::Stage;
		else if(typeStr == "generic")
			type = Type::Generic;
		else
			throw GeneralException("object manifest at '" + manifestPath.string() + "' contains invalid 'type' member: '" + typeStr + "'");
		
		if(manifest.HasMember("costumes")  &&  manifest["costumes"].IsArray())
		{
			Value& costumesArray = manifest["costumes"];
			for(Value::ValueIterator it = costumesArray.Begin(); it != costumesArray.End(); ++it)
			{
				auto i = it - costumesArray.Begin();
				Value& v = *it;
				std::string msgBegin("entry " + std::to_string(i) + " in 'costumes' in object manifest at '" + manifestPath.string() + "'");
				
				if(!v.IsObject())
					throw GeneralException(msgBegin + " is not an object");
				
				//check and get path
				std::shared_ptr<Costume> newCostume = std::make_shared<Costume>();
				if(!v.HasMember("path")  ||  !v["path"].IsString())
					throw GeneralException(msgBegin + " is missing string member 'path'");
				fs::path newCostumePath(objectPath / "costumes" / v["path"].GetString());
				Utilities::validateAllowedFileExtensions(allowedCostumeExts, newCostumePath);
				newCostume->loadFromPath(newCostumePath);
				newCostume->setResourceIndex(costumes.size());
				
				//check and get name
				if(!v.HasMember("name")  ||  !v["name"].IsString())
				{
					if(verboseOutput)
						std::cerr << "warning: " << msgBegin << " is missing string member 'name', defaulting to '" << newCostume->getName() << "'" << std::endl;
					if(v.HasMember("name"))
						v.RemoveMember("name");
					v.AddMember("name", Value(newCostume->getName().c_str(), alloc), alloc);
				}
				Utilities::validateIdentifier("string member 'name' in " + msgBegin, v["name"].GetString());
				newCostume->setName(v["name"].GetString());
				
				//check that name does not yet exist
				auto nameRedecl = std::find_if(costumes.begin(), costumes.end(), [&](std::shared_ptr<Costume> c) { return (c->getName() == newCostume->getName()); });
				if(nameRedecl != costumes.end())
					throw GeneralException("costume name '" + newCostume->getName() + "' in " + msgBegin + " already exists in entry " + std::to_string((*nameRedecl)->getResourceIndex()));
				
				//check and get rotationCenterX
				if(!v.HasMember("rotationCenterX")  ||  !v["rotationCenterX"].IsInt())
				{
					if(verboseOutput)
						std::cerr << "warning: " << msgBegin << " is missing integer member 'rotationCenterX', defaulting to '" << newCostume->getRotationCenterX() << "'" << std::endl;
					if(v.HasMember("rotationCenterX"))
						v.RemoveMember("rotationCenterX");
					v.AddMember("rotationCenterX", newCostume->getRotationCenterX(), alloc);
				}
				newCostume->setRotationCenterX(v["rotationCenterX"].GetInt());
				
				//check and get rotationCenterY
				if(!v.HasMember("rotationCenterY")  ||  !v["rotationCenterY"].IsInt())
				{
					if(verboseOutput)
						std::cerr << "warning: " << msgBegin << " is missing integer member 'rotationCenterY', defaulting to '" << newCostume->getRotationCenterY() << "'" << std::endl;
					if(v.HasMember("rotationCenterY"))
						v.RemoveMember("rotationCenterY");
					v.AddMember("rotationCenterY", newCostume->getRotationCenterY(), alloc);
				}
				newCostume->setRotationCenterY(v["rotationCenterY"].GetInt());
				
				//finally add costume to object
				addCostume(newCostume);
			}
		}
		else if(verboseOutput)
			std::cerr << "warning: object manifest at '" << manifestPath << "' is missing array member 'costumes'" << std::endl;
		if(costumes.size() == 0)
			throw GeneralException("object at '" + objectPath.string() + "' needs at least one costume");
		
		if(manifest.HasMember("sounds")  &&  manifest["sounds"].IsArray())
		{
			Value& soundsArray = manifest["sounds"];
			for(Value::ValueIterator it = soundsArray.Begin(); it != soundsArray.End(); ++it)
			{
				auto i = it - soundsArray.Begin();
				Value& v = *it;
				std::string msgBegin("entry " + std::to_string(i) + " in 'sounds' in object manifest at '" + manifestPath.string() + "'");
				
				if(!v.IsObject())
					throw GeneralException(msgBegin + " is not an object");
				
				//check and get path
				std::shared_ptr<Sound> newSound = std::make_shared<Sound>();
				if(!v.HasMember("path")  ||  !v["path"].IsString())
					throw GeneralException(msgBegin + " is missing string member 'path'");
				fs::path newSoundPath(objectPath / "sounds" / v["path"].GetString());
				Utilities::validateAllowedFileExtensions(allowedSoundExts, newSoundPath);
				newSound->loadFromPath(objectPath / "sounds" / v["path"].GetString());
				
				//check and get name
				if(!v.HasMember("name")  ||  !v["name"].IsString())
				{
					if(verboseOutput)
						std::cerr << "warning: " << msgBegin << " is missing string member 'name', defaulting to '" << newSound->getName() << "'" << std::endl;
					if(v.HasMember("name"))
						v.RemoveMember("name");
					v.AddMember("name", Value(newSound->getName().c_str(), alloc), alloc);
				}
				Utilities::validateIdentifier("string member 'name' in " + msgBegin, v["name"].GetString());
				newSound->setName(v["name"].GetString());
				
				//finally add sound to object
				addSound(newSound);
			}
		}
		else if(verboseOutput)
			std::cerr << "warning: object manifest at '" << manifestPath << "' is missing array member 'sounds'" << std::endl;
	}
	
	Object::Type Object::getType()
	{
		return type;
	}

	const fs::path& Object::getObjectPath()
	{
		return objectPath;
	}
	
	const std::string& Object::getName()
	{
		return name;
	}
	
	rapidjson::Document& Object::getManifest()
	{
		return manifest;
	}
	
	std::vector<std::shared_ptr<Costume>>& Object::getCostumes()
	{
		return costumes;
	}
	
	std::vector<std::shared_ptr<Sound>>& Object::getSounds()
	{
		return sounds;
	}
	
	std::shared_ptr<Costume> Object::getCurrentCostume()
	{
		return currentCostume;
	}
	
	std::shared_ptr<Sound> Object::getCurrentSound()
	{
		return currentSound;
	}
	
	void Object::setType(Object::Type newType)
	{
		type = newType;
	}
	
	void Object::setName(const std::string& newName)
	{
		name = newName;
	}
	
	void Object::addCostume(std::shared_ptr<Costume> newCostume)
	{
		costumes.push_back(newCostume);
	}
	
	void Object::addSound(std::shared_ptr<Sound> newSound)
	{
		sounds.push_back(newSound);
	}
}
