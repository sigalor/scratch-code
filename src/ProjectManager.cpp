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

namespace sc
{
	const ProjectManager::RequiredDirectoriesList ProjectManager::requiredFirstLevelDirectories		= { "bin", "gen", "objects" };
	const ProjectManager::RequiredDirectoriesList ProjectManager::requiredObjectDirectories			= { "costumes", "scripts", "sounds" };

	const ProjectManager::RequiredFilesList ProjectManager::requiredFirstLevelFiles =
	{
		{
			"manifest.json",
			[](const fs::path& filepath, ProjectManager* projMgr)
			{
				using namespace rapidjson;
	
				Document doc;
				Document::AllocatorType& alloc = doc.GetAllocator();
		
				doc.SetObject();
				doc.AddMember("user", "your_username", alloc);
				doc.AddMember("title", Value(projMgr->getProjectName().c_str(), alloc), alloc);						//cannot use .c_str() directly, because the resulting char* would not have safe life cycle, from https://github.com/miloyip/rapidjson/issues/738#issuecomment-247340768
				
				Utilities::writeDocumentToFile(filepath, doc);
			}
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
			std::shared_ptr<Object> newObject = std::make_shared<Object>(e.path(), Object::manifestRootEntryValueBase);
			
			auto otherStageObject = std::find_if(objects.begin(), objects.end(), [](std::shared_ptr<Object> obj) { return (obj->getType() == Object::Type::Stage); });
			if(newObject->getType() == Object::Type::Stage)
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
			if(o->getType() != Object::Type::Stage)
			{
				o->buildJSON(tempValue, alloc);
				docDest["children"].PushBack(tempValue, alloc);
			}
		}
	}





	ProjectManager::ProjectManager()
	{

	}

	ProjectManager::ProjectManager(const fs::path& newPathPrefix, const std::string& newProjectName) : pathPrefix(newPathPrefix), projectPath(newPathPrefix / newProjectName), projectName(newProjectName)
	{

	}

	void ProjectManager::initialize()
	{
		if(fs::exists(projectPath))
			throw GeneralException("'" + projectName + "' already exists as a " + Utilities::fileTypeToString(projectName));
	
		try
		{
			fs::create_directory(projectPath);
			createRequiredDirectories(requiredFirstLevelDirectories, projectPath);
			createRequiredFiles(requiredFirstLevelFiles, projectPath);
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
		
		//stage object has to exist
		addObject("Stage", projectPath / "objects/stage", Object::Type::Stage);
		
		//output final input message indicating success
		std::cout << "successfully created project tree for '" + projectName + "'" << std::endl;
	}

	void ProjectManager::addObject(const std::string& objName, const fs::path& objPath, Object::Type objType)
	{
		if(fs::exists(objPath))
			throw GeneralException("'" + fs::relative(objPath).string() + "' already exists as a " + Utilities::fileTypeToString(objPath));
		std::shared_ptr<Object> objectWithSameName(getObject(objName));
		if(objectWithSameName != nullptr)
			throw GeneralException("object called '" + objName + "' already exists at '" + fs::relative(objectWithSameName->getObjectPath()).string() + "'");
		
		try
		{
			createRequiredDirectories(requiredObjectDirectories, objPath);
			createRequiredFiles(requiredObjectFiles, objPath);
			
			objects.push_back(std::make_shared<Object>(objPath, Object::manifestRootEntryValueBase, false, true, objType));
			objects.back()->setName(objName);
			objects.back()->saveAndReload();
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
	
		std::cout << "successfully added object '" << objName << "' to project '" << projectName + "'" << std::endl;
	}
	
	void ProjectManager::addObject(const std::string& objName, Object::Type objType)
	{
		addObject(objName, projectPath / "objects" / objName, objType);
	}

	void ProjectManager::validate()
	{
		//check that project name is valid
		Utilities::validateIdentifier("project name", projectName);
		
		//check that required directories and files exist
		std::string objectName;
		try
		{
			validateRequiredDirectories(requiredFirstLevelDirectories, projectPath);
			if(objects.size() == 0)
				loadAllObjects();
			validateRequiredFiles(requiredFirstLevelFiles, projectPath);
		}
		catch(const GeneralException& e)
			{ throw GeneralException(std::string("invalid project tree: ") + e.what()); }
		
		std::cout << "successfully validated project '" << projectName << "'" << std::endl;
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
		
		fs::path binaryPath(projectPath / "bin" / (projectName + ".sb2"));
		fs::remove(binaryPath);
		for(fs::directory_entry& e : fs::directory_iterator(projectPath / "gen"))
			ZipFile::AddFile(binaryPath.string(), e.path().string());
		
		std::cout << "successfully built project '" << projectName << "'" << std::endl;
	}

	void ProjectManager::clean()
	{
		validate();
	}

	const fs::path& ProjectManager::getPathPrefix()
	{
		return pathPrefix;
	}

	const std::string& ProjectManager::getProjectName()
	{
		return projectName;
	}

	void ProjectManager::setProjectPath(const fs::path& newProjectPath)
	{
		projectPath = newProjectPath;
		pathPrefix = projectPath.parent_path();
		projectName = projectPath.filename().string();
	}

	void ProjectManager::setPathPrefix(const fs::path& newPathPrefix)
	{
		pathPrefix = newPathPrefix;
		projectPath = pathPrefix / projectName;
	}

	void ProjectManager::setProjectName(const std::string& newProjectName)
	{
		projectName = newProjectName;
		projectPath = pathPrefix / projectName;
	}
}
