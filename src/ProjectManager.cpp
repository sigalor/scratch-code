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
	const ProjectManager::RequiredDirectoriesList ProjectManager::requiredFirstLevelDirectories		= { "bin", "gen", "objects" };
	const ProjectManager::RequiredDirectoriesList ProjectManager::requiredObjectDirectories			= { "costumes", "scripts", "sounds" };

	const ProjectManager::RequiredFilesList ProjectManager::requiredFirstLevelFiles =
	{
		{
			"manifest.json",
			[](const fs::path& filepath, ProjectManager* projMgr) { Utilities::createFile(filepath, "{}"); }
		}
	};
	
	const ProjectManager::RequiredFilesList ProjectManager::requiredObjectFiles =
	{
		{
			"objectManifest.json",
			[](const fs::path& filepath, ProjectManager* projMgr) { Utilities::createFile(filepath, "{}"); }
		}
	};
	
	
	
	
	
	void ProjectManager::createRequiredDirectories(const RequiredDirectoriesList& reqDirs, const fs::path& dirPrefix)
	{
		for(auto& f : reqDirs)
			fs::create_directories(dirPrefix / f);																	//fs::create_directories acts like "mkdir -p", i.e. it creates missing parents as well
	}

	void ProjectManager::createRequiredFiles(const ProjectManager::RequiredFilesList& reqFiles, const fs::path& dirPrefix)
	{
		for(auto& f : reqFiles)
		{
			fs::path currPath(dirPrefix / f.first);
			fs::create_directories(currPath.parent_path());
			f.second(currPath, this);																				//the pair's second element is a function containing the building instructions for the specified file and creates that file
		}
	}

	void ProjectManager::validateRequiredDirectories(const ProjectManager::RequiredDirectoriesList& reqDirs, const fs::path& dirPrefix)
	{
		for(auto& f : reqDirs)
			Utilities::validateFile(dirPrefix / f, fs::file_type::directory_file);
	}

	void ProjectManager::validateRequiredFiles(const ProjectManager::RequiredFilesList& reqFiles, const fs::path& dirPrefix)
	{
		for(auto& f : reqFiles)
			Utilities::validateFile(dirPrefix / f.first, fs::file_type::regular_file);
	}
	
	
	
	
	
	void ProjectManager::loadAllObjects()
	{
		for(fs::directory_entry& e : fs::directory_iterator(projectPath / "objects"))
		{
			std::shared_ptr<Object> newObject = std::make_shared<Object>(e.path());
			
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
		Value tempValue, childrenArray(kArrayType);
		
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
				docDest["children"].PushBack(tempValue, alloc);
			}
		}
	}





	ProjectManager::ProjectManager(const fs::path& newProjectPath) : ManifestUser(newProjectPath / "manifest.json", ManifestDefinitions::ProjectManagerManifest::rootEntry, ManifestDefinitions::ProjectManagerManifest::rootEntryValueBase, false), projectPath(newProjectPath)
	{
		//empty
	}

	void ProjectManager::initialize()
	{
		if(fs::exists(projectPath))
			throw GeneralException("'" + getTitle() + "' already exists as a " + Utilities::fileTypeToString(getTitle()));
		
		try
		{
			fs::create_directory(projectPath);
			createRequiredDirectories(requiredFirstLevelDirectories, projectPath);
			createRequiredFiles(requiredFirstLevelFiles, projectPath);
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
		
		//load manifest
		isInitialization = true;
		loadManifestInternal(this, false);
		saveAndReloadInternal(this);
		isInitialization = true;
		
		//stage object has to exist
		addObject("Stage", projectPath / "objects/stage", op::Type::Stage);
		
		//output final input message indicating success
		std::cout << "successfully created project tree for '" + getTitle() + "'" << std::endl;
	}

	void ProjectManager::addObject(const std::string& objName, const fs::path& objPath, op::Type objType)
	{
		if(!isInitialization)
			validate();
		if(fs::exists(objPath))
			throw GeneralException("'" + fs::relative(objPath).string() + "' already exists as a " + Utilities::fileTypeToString(objPath));
		std::shared_ptr<Object> objectWithSameName(getObject(objName));
		if(objectWithSameName != nullptr)
			throw GeneralException("object called '" + objName + "' already exists at '" + fs::relative(objectWithSameName->getObjectPath()).string() + "'");
		
		try
		{
			createRequiredDirectories(requiredObjectDirectories, objPath);
			createRequiredFiles(requiredObjectFiles, objPath);
			
			objects.push_back(std::make_shared<Object>(objPath, false, true, objType));
			objects.back()->setName(objName);
			objects.back()->saveAndReload();
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
	
		std::cout << "successfully added object '" << objName << "' to project '" << getTitle() + "'" << std::endl;
	}
	
	void ProjectManager::addObject(const std::string& objName, op::Type objType)
	{
		addObject(objName, projectPath / "objects" / objName, objType);
	}

	void ProjectManager::validate()
	{
		//the project's path has to exist and be a directory of course
		Utilities::validateFile(projectPath, fs::file_type::directory_file);
		
		//check that required directories and files exist
		try
		{
			validateRequiredDirectories(requiredFirstLevelDirectories, projectPath);
			if(objects.size() == 0)
				loadAllObjects();
			validateRequiredFiles(requiredFirstLevelFiles, projectPath);
		}
		catch(const GeneralException& e)
			{ throw GeneralException(std::string("invalid project tree: ") + e.what()); }
		
		//load the manifest
		loadManifestInternal(this);
		
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
			fs::remove_all(projectPath / "gen");
			fs::create_directory(projectPath / "gen");
			buildObjectResourceList(costumes);
			buildObjectResourceList(sounds);
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
		
		rapidjson::Document doc;
		buildProjectJSON(costumes[0], doc);
		Utilities::writeDocumentToFile(projectPath / "gen/project.json", doc);
		
		fs::path binaryPath(projectPath / "bin" / (getTitle() + ".sb2"));
		fs::remove(binaryPath);
		for(fs::directory_entry& e : fs::directory_iterator(projectPath / "gen"))
			ZipFile::AddFile(binaryPath.string(), e.path().string());
		
		std::cout << "successfully built project '" << getTitle() << "'" << std::endl;
	}

	void ProjectManager::clean()
	{
		validate();
	}
	
	
	
	

	const fs::path& ProjectManager::getProjectPath()
	{
		return projectPath;
	}
	
	std::string ProjectManager::getTitle()
	{
		return manifest["title"].GetString();
	}
	
	std::string ProjectManager::getUsername()
	{
		return manifest["username"].GetString();
	}

	void ProjectManager::setTitle(const std::string& newTitle)
	{
		//Utilities::validateIdentifier("project title", newTitle);
		manifest["title"].SetString(newTitle.c_str(), manifest.GetAllocator());
	}
	
	void ProjectManager::setUsername(const std::string& newUsername)
	{
		//Utilities::validateIdentifier("username", newUsername);
		manifest["username"].SetString(newUsername.c_str(), manifest.GetAllocator());
	}
}
