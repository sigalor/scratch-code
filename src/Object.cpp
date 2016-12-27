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

namespace sc
{
	const std::vector<std::string> Object::allowedCostumeExts	= { ".png" };
	const std::vector<std::string> Object::allowedScriptExts	= { ".sc" };
	const std::vector<std::string> Object::allowedSoundExts		= { ".wav" };
	
	/*const LocalParamsManifestStructure Object::localParamsManifestStructure(
	{
		LocalParamsManifestEntry("objectName", false),
		LocalParamsManifestEntry("type", false),
	});*/
	
	const ManifestEntry<Object> Object::manifestRootEntry(ManifestStructure<Object>(
	{
		ManifestEntry<Object>
		(
			"objectName",
			mep::Type::String,
			mep::Importance::OptionalWithWarning,
			std::make_tuple
			(
				/* condition */			nullptr,
				/* alternative */		[](Object* obj) { return obj->getObjectPath().filename().string(); },
				/* processor */			[](Object* obj, const mep::TypeVariant& val) { obj->setName(boost::get<std::string>(val)); }
			)
		),
		ManifestEntry<Object>
		(
			"type",
			mep::Type::String,
			mep::Importance::OptionalWithWarning,
			std::make_tuple
			(
				/* condition */			nullptr,
				/* alternative */		[](Object* obj)
										{
											if(obj->getIsInitialization())
											{
												switch(obj->getTypeForInitialization())
												{
													case Object::Type::Stage	: return "stage";					//these are the values the JSON file shall have
													case Object::Type::Generic	: return "generic";
													default						: return "error";
												}
											}
											return "generic";
										},
				/* processor */			[](Object* obj, const mep::TypeVariant& val)
										{
											std::string typeStr(boost::get<std::string>(val));
											if(typeStr == "stage")
												obj->setType(Object::Type::Stage);
											else if(typeStr == "generic")
												obj->setType(Object::Type::Generic);
											else
												throw GeneralException("value '" + typeStr + "' is invalid");
										}
			)
		),
		ManifestEntry<Object>
		(
			"costumes",
			mep::Type::Array,
			mep::Importance::OptionalWithWarning,
			std::make_tuple
			(
				/* condition */				nullptr,
				/* preProcessor */			nullptr,
				/* elementPreProcessor */	[](Object* obj)
											{
												obj->addCostume(std::make_shared<Costume>());
												obj->setCurrentlyProcessedCostume(obj->getCostumes().back());
												obj->getCurrentlyProcessedCostume()->setResourceIndex(obj->getCostumes().size() - 1);
											},
				/* elementPostProcessor */	nullptr,
				/* postProcessor */			[](Object* obj)
											{
												if(obj->getIsInitialization())
												{
													using namespace rapidjson;
												
													//if initialization is currently working, the object should not have any costumes yet
													if(obj->getCostumes().size() != 0)
														throw GeneralException("number of costumes before initialization needs to be 0");
												
													Object::Type				objectType = obj->getType();
													std::string					newCostumeFilename = (objectType==Object::Type::Stage ? "backdrop1.png" : (objectType==Object::Type::Generic ? "costume1.png" : "error.png"));
													fs::path					newCostumePath(obj->getObjectPath() / "costumes" / newCostumeFilename);
													Value						newCostumeEntry(kObjectType);
													Document::AllocatorType&	alloc = obj->getManifest().GetAllocator();
													
													//create generic costumes (white fullscreen for stage, red square for generic)
													if(objectType == Object::Type::Stage)
														Utilities::writePlainPNGToFile(newCostumePath, 480, 360, 255, 255, 255, 255);
													else if(objectType == Object::Type::Generic)
														Utilities::writePlainPNGToFile(newCostumePath, 100, 100, 255, 0, 0, 255);
													
													//add an entry for the new costume to the manifest
													newCostumeEntry.AddMember("path", Value(newCostumeFilename.c_str(), alloc), alloc);
													obj->getManifest()["costumes"].PushBack(newCostumeEntry, alloc);
													
													//load the new costume as if it would have been a regular one that also needs to be pre-processed
													ManifestEntryValue<bool>& costumesEntryValue = obj->getPredefinedValues().getEntry("costumes");
													costumesEntryValue.addArrayEntry(false);
													Object::manifestRootEntry.children.getEntry("costumes").elementPreProcessor(obj);
													obj->getCostumes().back()->loadFromPath(newCostumePath);
													Object::manifestRootEntry.children.validateJSON(obj, obj->getManifest()["costumes"][0], alloc, Object::manifestRootEntry.children.getEntry("costumes").children, obj->getObjectPath() / "objectManifest.json", costumesEntryValue.children.back(), false, true, false);
													
													//output final info message (do not use "obj->getName()" here, as the "ProjectManager::addObject" function sets the desired name later)
													std::cerr << "successfully added costume '" << obj->getCostumes().back()->getName() << "' to object at '" << fs::relative(obj->getObjectPath()).string() << "'" << std::endl;
												}
											}
			),
			ManifestStructure<Object>(
			{
				ManifestEntry<Object>
				(
					"path",
					mep::Type::String,
					mep::Importance::Required,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		nullptr,
						/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->loadFromPath(obj->getObjectPath() / "costumes" / boost::get<std::string>(val)); }
					)
				),
				ManifestEntry<Object>
				(
					"name",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedCostume()->getResourcePath().stem().string(); },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->setName(boost::get<std::string>(val)); }
					)
				),
				ManifestEntry<Object>
				(
					"rotationCenterX",
					mep::Type::Integer,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedCostume()->getWidth() / 2; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->setRotationCenterX(boost::get<int>(val)); }
					)
				),
				ManifestEntry<Object>
				(
					"rotationCenterY",
					mep::Type::Integer,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedCostume()->getHeight() / 2; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->setRotationCenterY(boost::get<int>(val)); }
					)
				)
			})
		),
		ManifestEntry<Object>
		(
			"currentCostumeIndex",
			mep::Type::Integer,
			mep::Importance::OptionalWithWarning,
			std::make_tuple
			(
				/* condition */			nullptr,
				/* alternative */		[](Object* obj)									{ return 0; },
				/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->setCurrentCostumeIndex(boost::get<int>(val)); }		//all costumes are available at this point
			)
		)
	}));
	
	const ManifestEntryValue<bool> Object::manifestRootEntryValueBase(Object::manifestRootEntry);
	
	const std::string Object::typeToString(Object::Type type)
	{
		switch(type)
		{
			case Type::Stage	: return "stage";																	//these are the string representations the user shall see in program outputs, NOT the ones that are for the JSON file!
			case Type::Generic	: return "generic";
			default				: return "(unknown)";
		}
	}
	
	
	
	

	Object::Object()
	{
	
	}
	
	Object::Object(const fs::path& newObjectPath, const ManifestEntryValue<bool>& newPredefinedValues, bool verboseOutput, bool newIsInitialization, Type newTypeForInitialization) : predefinedValues(newPredefinedValues)
	{
		loadFromPath(newObjectPath, verboseOutput, newIsInitialization, newTypeForInitialization);
	}
	
	void Object::loadFromPath(const fs::path& newObjectPath, bool verboseOutput, bool newIsInitialization, Type newTypeForInitialization)
	{
		using namespace rapidjson;
	
		objectPath = newObjectPath;
		predefinedValues.resetAll(false);
		isInitialization = newIsInitialization;
		typeForInitialization = newTypeForInitialization;
		Utilities::validateFile(objectPath, fs::file_type::directory_file);
		manifestRootEntry.children.validateJSON(this, objectPath / "objectManifest.json", manifest, predefinedValues, false, true, verboseOutput);
		
		if(getType() == Type::Stage)
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
	
	void Object::purgeNonPredefinedManifestEntries(rapidjson::Value& currValue, ManifestEntryValue<bool>& currPredefinedValues)			//purges all entries from the "manifest" object that were not there when the manifest was loaded
	{
		using namespace rapidjson;
	
		if(!currValue.IsObject())
			throw GeneralException("cannot purge manifest entries in JSON non-object");
		if(currPredefinedValues.type != mep::Type::Object)
			throw GeneralException("cannot purge manifest entries using manifest entry value non-object");
		
		for(ManifestEntryValue<bool>& e : currPredefinedValues.children)
		{
			//here are quite some places for inconsistencies to happen...
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
	
	void Object::saveAndReload(bool verboseOutput)
	{
		purgeNonPredefinedManifestEntries(manifest, predefinedValues);
		Utilities::writeDocumentToFile(objectPath / "objectManifest.json", manifest);
		manifest.SetObject();
		isInitialization = false;
		costumes.clear();
		sounds.clear();
		scripts = nullptr;
		currentlyProcessedCostume = nullptr;
		currentlyProcessedSound = nullptr;
		loadFromPath(objectPath, verboseOutput);
	}
	
	
	
	
	
	Object::Type Object::getType()
	{
		if(std::string(manifest["type"].GetString()) == "stage")
			return Type::Stage;
		else if(std::string(manifest["type"].GetString()) == "generic")
			return Type::Generic;
		return Type::Invalid;
	}

	const fs::path& Object::getObjectPath()
	{
		return objectPath;
	}
	
	std::string Object::getName()
	{
		return manifest["objectName"].GetString();
	}
	
	rapidjson::Document& Object::getManifest()
	{
		return manifest;
	}
	
	ManifestEntryValue<bool>& Object::getPredefinedValues()
	{
		return predefinedValues;
	}
	
	int Object::getCurrentCostumeIndex()
	{
		return manifest["currentCostumeIndex"].GetInt();
	}
	
	std::shared_ptr<Costume> Object::getPenLayer()
	{
		if(getType() != Type::Stage)
			throw GeneralException("object '" + getName() + "' is not of type '" + typeToString(getType()) + "', thus it does not have a pen layer");
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
	
	void Object::setType(Object::Type newType)
	{
		switch(newType)
		{
			case Type::Stage	: manifest["type"].SetString("stage"); break;
			case Type::Generic	: manifest["type"].SetString("generic"); break;
			default				: break;
		}
	}
	
	void Object::setName(const std::string& newName)
	{
		Utilities::validateIdentifier("object name", newName);
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
		if(getType() != Type::Stage)
			throw GeneralException("object '" + getName() + "' is not of type '" + typeToString(getType()) + "', thus no pen layer may be assigned to it");
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
	
	
	
	
	
	bool Object::getIsInitialization()
	{
		return isInitialization;
	}
	
	Object::Type Object::getTypeForInitialization()
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
		if(currentlyProcessedCostume != nullptr)
		{
			auto otherCostume = std::find_if(costumes.begin(), costumes.end(), [&](std::shared_ptr<Costume> costume)
			{
				if(costume == currentlyProcessedCostume)
					return false;
				return (costume->getName() == currentlyProcessedCostume->getName());
			});
			if(otherCostume != costumes.end())
				throw GeneralException("object '" + getName() + "' may not contain two costumes with the same name: candidates are at '" + fs::relative((*otherCostume)->getResourcePath()).string() + "' and '" + fs::relative(currentlyProcessedCostume->getResourcePath()).string() + "'");
		}
		currentlyProcessedCostume = newCurrentlyProcessedCostume;
	}
	
	void Object::setCurrentlyProcessedSound(std::shared_ptr<Sound> newCurrentlyProcessedSound)
	{
		currentlyProcessedSound = newCurrentlyProcessedSound;
	}
}
