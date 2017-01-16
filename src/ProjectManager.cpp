/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/ProjectManager.cpp
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



#include "ProjectManager.hpp"



namespace fs = boost::filesystem;
namespace mep = sc::ManifestEntryParams;
namespace op = sc::ObjectParams;

namespace sc
{
	void ProjectManager::loadAllObjects()
	{
		for(fs::directory_entry& e : fs::directory_iterator(getPaths_objectsDirectory()))
		{
			std::shared_ptr<Object> newObject = std::make_shared<Object>(e.path(), this);
			
			auto otherStageObject = std::find_if(objects.begin(), objects.end(), [](std::shared_ptr<Object> obj) { return (obj->getType() == op::Type::Stage); });
			if(newObject->getType() == op::Type::Stage)
			{
				if(otherStageObject != objects.end())
					throw GeneralException("project may not contain more than one stage object: candidates are at '" + fs::relative(newObject->getObjectPath()).string() + "' and '" + fs::relative((*otherStageObject)->getObjectPath()).string() + "'");
				stageObject = newObject;
			}
			
			auto objectWithSameName = std::find_if(objects.begin(), objects.end(), [&](std::shared_ptr<Object> obj) { return (obj->getName() == newObject->getName()); });
			if(objectWithSameName != objects.end())
				throw GeneralException("project may not contain two objects with the same name: candidates are at '" + fs::relative(newObject->getObjectPath()).string() + "' and '" + fs::relative((*objectWithSameName)->getObjectPath()).string() + "'");
			
			objects.push_back(newObject);
		}
		
		if(stageObject == nullptr)
			throw GeneralException("project needs to contain at least one stage object");
	}
	
	std::shared_ptr<Object> ProjectManager::getObject(const std::string& objName)
	{
		auto retObject = std::find_if(objects.begin(), objects.end(), [&](std::shared_ptr<Object> obj) { return (obj->getName() == objName); });
		if(retObject == objects.end())
			return nullptr;
			//throw GeneralException("object with name '" + objName + "' not found");
		return *retObject;
	}
	
	void ProjectManager::buildProjectJSON(std::shared_ptr<Costume> penLayer, rapidjson::Document& docDest)
	{
		using namespace rapidjson;
		
		Document::AllocatorType& alloc = docDest.GetAllocator();
		Value tempValue, childrenArray(kArrayType), infoObject(kObjectType);
		int64_t indexInLibraryCounter = 1;
		
		stageObject->buildJSON(docDest, alloc);
		docDest.AddMember("penLayerMD5", Value((penLayer->getMD5Sum() + penLayer->getResourcePath().extension().string()).c_str(), alloc), alloc);
		docDest.AddMember("penLayerID", penLayer->getResourceID(), alloc);
		docDest.AddMember("tempoBPM", 60, alloc);
		docDest.AddMember("videoAlpha", 0.5, alloc);
		
		docDest.AddMember("children", childrenArray, alloc);
		for(auto o : objects)
		{
			if(o->getType() != op::Type::Stage)
			{
				o->buildJSON(tempValue, alloc);
				tempValue.AddMember("indexInLibrary", indexInLibraryCounter, alloc);
				docDest["children"].PushBack(tempValue, alloc);
				++indexInLibraryCounter;
			}
		}
		
		docDest.AddMember("info", infoObject, alloc);
		docDest["info"].AddMember("spriteCount", objects.size()-1, alloc);											//subtract 1 from "objects.size()", as there always is a single stage object
		docDest["info"].AddMember("scriptCount", 0, alloc);
		docDest["info"].AddMember("userAgent", Value(getInfo_userAgent().c_str(), alloc), alloc);
	}
	
	void ProjectManager::addObjectInternal(const std::string& objName, const fs::path& objPath, op::Type objType)
	{
		//important: no validation is happening here! It has been done either in "initialize()" or "addObject(...)"!
		
		//check for new object's uniqueness (in path and name)
		if(fs::exists(objPath))
			throw GeneralException("'" + fs::relative(objPath).string() + "' already exists as a " + Utilities::fileTypeToString(objPath));
		std::shared_ptr<Object> objectWithSameName(getObject(objName));
		if(objectWithSameName != nullptr)
			throw GeneralException("object called '" + objName + "' already exists at '" + fs::relative(objectWithSameName->getObjectPath()).string() + "'");
		
		//load the object (while "verboseOutput" is false to suppress warnings and "isInitialization" is true), then do some changes, finally save the modified object's manifest on the disk and reload it
		objects.push_back(std::make_shared<Object>(objPath, this, false, true, objType));
		objects.back()->setName(objName);
		objects.back()->saveAndReload();
		
		//output final success message
		std::cout << "successfully added object '" << objName << "' to project '" << getTitle() + "'" << std::endl;
	}
	
	
	
	
	
	ProjectManager::ProjectManager(const fs::path& newProjectPath) : ManifestUser(newProjectPath / "manifest.json", ManifestDefinitions::ProjectManagerManifest::rootEntry, ManifestDefinitions::ProjectManagerManifest::rootEntryValueBase, false), projectPath(newProjectPath)
	{
		//empty
	}

	void ProjectManager::initialize()
	{
		if(fs::exists(projectPath))
			throw GeneralException("'" + getTitle() + "' already exists as a " + Utilities::fileTypeToString(getTitle()));
		fs::create_directory(projectPath);
		
		//load manifest
		isInitialization = true;
		loadManifestInternal(this, false);
		saveAndReloadInternal(this);
		isInitialization = true;
		
		//stage object has to exist
		addObjectInternal("Stage", getPaths_objectsDirectory() / "stage", op::Type::Stage);
		
		//output final input message indicating success
		std::cout << "successfully created project tree for '" + getTitle() + "'" << std::endl;
	}
	
	void ProjectManager::addObject(const std::string& objName, op::Type objType)
	{
		//this function is just a shortcut
		validate();
		addObjectInternal(objName, getPaths_objectsDirectory() / objName, objType);
	}

	void ProjectManager::validate()
	{
		//the project's path has to exist and be a directory of course
		Utilities::validateFile(projectPath, fs::file_type::directory_file);
		
		//load the own manifest and all objects
		try
		{
			loadManifestInternal(this);
			if(objects.size() == 0)
				loadAllObjects();
		}
		catch(const GeneralException& e)
			{ throw GeneralException(std::string("invalid project tree: ") + e.what()); }
		
		//output final success message
		std::cout << "successfully validated project '" << getTitle() << "'" << std::endl;
	}

	void ProjectManager::build()
	{
		validate();
		/*for(auto o : objects)
		{
			std::cout << "Object '" << o->getName() << "':\n";
			std::cout << "    " << o->getCostumes().size() << " costume(s):\n";
			for(auto& c : o->getCostumes())
				std::cout << "        '" << c->getName() << "' at " << c->getResourcePath() << ", size: " << c->getWidth() << " x " << c->getHeight() << "\n";
			std::cout << "    " << o->getSounds().size() << " sound(s):\n";
			for(auto& s : o->getSounds())
				std::cout << "        '" << s->getName() << "' at " << s->getResourcePath() << ", sampleCount: " << s->getSampleCount() << ", rate: " << s->getRate() << "\n";
			std::cout << std::endl;
		}*/
		
		std::vector<std::shared_ptr<Costume>> costumes;
		std::vector<std::shared_ptr<Sound>> sounds;
		costumes.push_back(stageObject->getPenLayer());																//"penLayer" is the very first "costume" and ID 0 is reserved for it		costumes.push_back(std::make_shared<Costume>("objects/stage/penLayer/penLayer.png"));						
		costumes.back()->setResourceID(0);
		for(auto& o : objects)
		{
			for(auto c : o->getCostumes())
			{
				c->setResourceID(costumes.size());
				costumes.push_back(c);
			}
			for(auto s : o->getSounds())
			{
				s->setResourceID(sounds.size());
				sounds.push_back(s);
			}
		}
		
		try
		{
			clean(false);
			buildObjectResourceList(costumes);
			buildObjectResourceList(sounds);
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
		
		rapidjson::Document doc;
		buildProjectJSON(costumes[0], doc);
		Utilities::writeDocumentToFile(getPaths_generatedFilesDirectory() / "project.json", doc);
		
		fs::path binaryPath(getPaths_binariesDirectory() / (getTitle() + ".sb2"));
		fs::remove(binaryPath);
		for(fs::directory_entry& e : fs::directory_iterator(getPaths_generatedFilesDirectory()))
			ZipFile::AddFile(binaryPath.string(), e.path().string());
		
		std::cout << "successfully built project '" << getTitle() << "'" << std::endl;
	}

	void ProjectManager::clean(bool doValidation)
	{
		if(doValidation)
			validate();
		Utilities::clearDirectory(getPaths_binariesDirectory());
		Utilities::clearDirectory(getPaths_generatedFilesDirectory());
		
		std::cout << "successfully cleaned project '" << getTitle() << "'" << std::endl;
	}
	
	
	
	

	const fs::path& ProjectManager::getProjectPath()
	{
		return projectPath;
	}
	
	std::shared_ptr<Object> ProjectManager::getStageObject()
	{
		return stageObject;
	}
	
	std::string ProjectManager::getTitle()
	{
		return manifest["title"].GetString();
	}
	
	std::string ProjectManager::getUsername()
	{
		return manifest["username"].GetString();
	}
	
	fs::path ProjectManager::getPaths_binariesDirectory()
	{
		return projectPath / manifest["paths"]["binariesDirectory"].GetString();
	}
	
	fs::path ProjectManager::getPaths_generatedFilesDirectory()
	{
		return projectPath / manifest["paths"]["generatedFilesDirectory"].GetString();
	}
	
	fs::path ProjectManager::getPaths_objectsDirectory()
	{
		return projectPath / manifest["paths"]["objectsDirectory"].GetString();
	}
	
	std::string ProjectManager::getInfo_userAgent()
	{
		return manifest["info"]["userAgent"].GetString();
	}

	void ProjectManager::setTitle(const std::string& newTitle)
	{
		manifest["title"].SetString(newTitle.c_str(), manifest.GetAllocator());
	}
	
	void ProjectManager::setUsername(const std::string& newUsername)
	{
		//Utilities::validateIdentifier("username", newUsername);
		manifest["username"].SetString(newUsername.c_str(), manifest.GetAllocator());
	}
	
	void ProjectManager::setPaths_binariesDirectory(const std::string& newVal)
	{
		Utilities::validateFile(projectPath / newVal, fs::file_type::directory_file);
		manifest["paths"]["binariesDirectory"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void ProjectManager::setPaths_generatedFilesDirectory(const std::string& newVal)
	{
		Utilities::validateFile(projectPath / newVal, fs::file_type::directory_file);
		manifest["paths"]["generatedFilesDirectory"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void ProjectManager::setPaths_objectsDirectory(const std::string& newVal)
	{
		Utilities::validateFile(projectPath / newVal, fs::file_type::directory_file);
		manifest["paths"]["objectsDirectory"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
	
	void ProjectManager::setInfo_userAgent(const std::string& newVal)
	{
		manifest["info"]["userAgent"].SetString(newVal.c_str(), manifest.GetAllocator());
	}
}
