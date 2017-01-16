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
	Object::Object(const fs::path& newObjectPath, ProjectManager* newParentProjectManager, bool verboseOutput, bool newIsInitialization, op::Type newTypeForInitialization) : ManifestUser(newObjectPath / "objectManifest.json", ManifestDefinitions::ObjectManifest::rootEntry, ManifestDefinitions::ObjectManifest::rootEntryValueBase, newIsInitialization), parentProjectManager(newParentProjectManager)
	{
		loadFromPath(newObjectPath, verboseOutput, newTypeForInitialization);
	}
	
	void Object::loadFromPath(const fs::path& newObjectPath, bool verboseOutput, op::Type newTypeForInitialization)
	{
		objectPath = newObjectPath;
		typeForInitialization = newTypeForInitialization;
		if(isInitialization  &&  !fs::exists(newObjectPath))
			fs::create_directory(newObjectPath);
		Utilities::validateFile(objectPath, fs::file_type::directory_file);
		loadManifestInternal(this, verboseOutput);
	}
	
	void Object::buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
	{
		using namespace rapidjson;
		
		Value valueBuffer;
		Value costumesArray(kArrayType), soundsArray(kArrayType);
		Translator translator(this, parsingDriver, alloc);
		
		valDest.SetObject();
		valDest.AddMember("objName", Value(getName().c_str(), alloc), alloc);
		
		//add script
		translator.translate(scripts, valueBuffer);
		valDest.AddMember("scripts", valueBuffer, alloc);
		
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
		
		//add member which specifies the index of the costume currently active
		valDest.AddMember("currentCostumeIndex", getAppearance_currentCostumeIndex(), alloc);
		
		//add members specifically for generic objects
		if(getType() == op::Type::Generic)
		{
			//transformation
			valDest.AddMember("scratchX", getTransformation_positionX(), alloc);
			valDest.AddMember("scratchY", getTransformation_positionY(), alloc);
			valDest.AddMember("scale", getTransformation_scale(), alloc);
			valDest.AddMember("direction", getTransformation_direction(), alloc);
			
			//behavior
			std::string rotationStyleString;
			switch(getBehavior_rotationStyle())
			{
				case op::RotationStyle::Normal		: rotationStyleString = "normal"; break;
				case op::RotationStyle::LeftRight	: rotationStyleString = "leftRight"; break;
				case op::RotationStyle::None		: rotationStyleString = "none"; break;
				default								: break;
			}
			valDest.AddMember("rotationStyle", Value(rotationStyleString.c_str(), alloc), alloc);
			valDest.AddMember("isDraggable", getBehavior_isDraggable(), alloc);
			
			//appearance
			valDest.AddMember("visible", getAppearance_isVisible(), alloc);
			
			//other (sprite info is currently always empty)
			Value spriteInfoObject(kObjectType);
			valDest.AddMember("spriteInfo", spriteInfoObject, alloc);
		}
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
	
	ProjectManager* Object::getParentProjectManager()
	{
		return parentProjectManager;
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
	
	
	
	
	
	std::string Object::getName()
	{
		return manifest["objectName"].GetString();
	}
	
	op::Type Object::getType()
	{
		return op::jsonStringToType(manifest["type"].GetString());
	}
	
	fs::path Object::getPaths_costumesDirectory()
	{
		return objectPath / manifest["paths"]["costumesDirectory"].GetString();
	}
	
	fs::path Object::getPaths_scriptsDirectory()
	{
		return objectPath / manifest["paths"]["scriptsDirectory"].GetString();
	}
	
	fs::path Object::getPaths_soundsDirectory()
	{
		return objectPath / manifest["paths"]["soundsDirectory"].GetString();
	}
	
	fs::path Object::getPaths_penLayer()
	{
		return objectPath / manifest["paths"]["penLayer"].GetString();
	}
	
	fs::path Object::getMainScriptFile()
	{
		return getPaths_scriptsDirectory() / manifest["mainScriptFile"].GetString();
	}
	
	double Object::getTransformation_positionX()
	{
		return manifest["transformation"]["positionX"].GetDouble();
	}
	
	double Object::getTransformation_positionY()
	{
		return manifest["transformation"]["positionY"].GetDouble();
	}
	
	double Object::getTransformation_scale()
	{
		return manifest["transformation"]["scale"].GetDouble();
	}
	
	double Object::getTransformation_direction()
	{
		return manifest["transformation"]["direction"].GetDouble();
	}
	
	ObjectParams::RotationStyle Object::getBehavior_rotationStyle()
	{
		return op::jsonStringToRotationStyle(manifest["behavior"]["rotationStyle"].GetString());
	}
	
	bool Object::getBehavior_isDraggable()
	{
		return manifest["behavior"]["isDraggable"].GetBool();
	}
	
	bool Object::getAppearance_isVisible()
	{
		return manifest["appearance"]["isVisible"].GetBool();
	}
	
	int64_t Object::getAppearance_currentCostumeIndex()
	{
		return manifest["appearance"]["currentCostumeIndex"].GetInt64();
	}
	
	void Object::setName(const std::string& newName)
	{
		manifest["objectName"].SetString(newName.c_str(), manifest.GetAllocator());
	}
	
	void Object::setType(op::Type newType)
	{
		manifest["type"].SetString(op::typeToJSONString(newType).c_str(), manifest.GetAllocator());
	}
	
	void Object::setPaths_costumesDirectory(const std::string& newVal)
	{
		Utilities::validateFile(objectPath / newVal, fs::file_type::directory_file);
		manifest["paths"]["costumesDirectory"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void Object::setPaths_scriptsDirectory(const std::string& newVal)
	{
		Utilities::validateFile(objectPath / newVal, fs::file_type::directory_file);
		manifest["paths"]["scriptsDirectory"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void Object::setPaths_soundsDirectory(const std::string& newVal)
	{
		Utilities::validateFile(objectPath / newVal, fs::file_type::directory_file);
		manifest["paths"]["soundsDirectory"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void Object::setPaths_penLayer(const std::string& newVal)
	{
		Utilities::validateFile(objectPath / newVal, fs::file_type::regular_file);
		manifest["paths"]["penLayer"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void Object::setMainScriptFile(const std::string& newVal)
	{
		Utilities::validateFile(getPaths_scriptsDirectory() / newVal, fs::file_type::regular_file);
		manifest["mainScriptFile"].SetString(newVal.c_str(), manifest.GetAllocator());
		
		//actually parse the source file ("parsingDriver.parse" will throw a sc::GeneralException when a syntax error occurs)
		//TODO: what about "driver.setTraceLexing(true);" and "driver.setTraceParsing(true);"? Command-line parameters?
		scripts = std::make_shared<ast::StatementList>(nullptr);
		parsingDriver = std::make_shared<Driver>(scripts, this);
		parsingDriver->functionDefinitions.insert(parsingDriver->functionDefinitions.end(), OpcodeAliases::nativeFunctionDefinitions.begin(), OpcodeAliases::nativeFunctionDefinitions.end());
		parsingDriver->parse(getMainScriptFile());
	}
	
	void Object::setTransformation_positionX(double newVal)
	{
		manifest["transformation"]["positionX"].SetDouble(newVal);
	}
	
	void Object::setTransformation_positionY(double newVal)
	{
		manifest["transformation"]["positionY"].SetDouble(newVal);
	}
	
	void Object::setTransformation_scale(double newVal)
	{
		if(newVal < 0.0)
			throw GeneralException("scale value '" + std::to_string(newVal) + "' is out of range, may not be below 0");
		manifest["transformation"]["scale"].SetDouble(newVal);
	}
	
	void Object::setTransformation_direction(double newVal)
	{
		manifest["transformation"]["direction"].SetDouble(newVal);
	}
	
	void Object::setBehavior_rotationStyle(ObjectParams::RotationStyle newVal)
	{
		manifest["behavior"]["rotationStyle"].SetString(op::rotationStyleToJSONString(newVal).c_str(), manifest.GetAllocator());
	}
	
	void Object::setBehavior_isDraggable(bool newVal)
	{
		manifest["behavior"]["isDraggable"].SetBool(newVal);
	}
	
	void Object::setAppearance_isVisible(bool newVal)
	{
		manifest["appearance"]["isVisible"].SetBool(newVal);
	}
	
	void Object::setAppearance_currentCostumeIndex(int64_t newVal)
	{
		if(newVal < 0  ||  newVal >= (int64_t)costumes.size())
			throw GeneralException("costume index '" + std::to_string(newVal) + "' is out of range (" + std::to_string(costumes.size()) + " costumes available)");
		manifest["appearance"]["currentCostumeIndex"].SetInt64(newVal);
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
