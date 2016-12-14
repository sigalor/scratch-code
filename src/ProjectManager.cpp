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
	const std::string ProjectManager::allowedIdentifierCharacters = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	const ProjectManager::RequiredDirectoriesList ProjectManager::requiredFirstLevelDirectories		= { "bin", "objects" };
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
		},
		{
			"objects/stage/penLayer/penLayer.png",
			[](const fs::path& filepath, ProjectManager* projMgr) { Utilities::writePlainPNGToFile(filepath, 480, 360, 0, 0, 0, 0); }
		},
		{
			"objects/stage/costumes/backdrop1.png",
			[](const fs::path& filepath, ProjectManager* projMgr) { Utilities::writePlainPNGToFile(filepath, 480, 360, 255, 255, 255, 255); }
		}
	};
	
	const ProjectManager::RequiredFilesList ProjectManager::requiredObjectFiles =
	{
		{
			"scripts/main.sc",
			[](const fs::path& filepath, ProjectManager* projMgr)
			{
				Utilities::createFile(filepath);
			}
		}
	};

	const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedCostumeFileExtensions	= { ".png" };
	const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedScriptFileExtensions		= { ".sc" };
	const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedSoundFileExtensions		= { ".wav" };





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





	void ProjectManager::validateIdentifier(const std::string& name, const std::string& identifier)
	{
		//trying to match a regex like [_A-Za-z][_A-Za-z0-9]* would be possible, but the std::regex library is way too big for such a simple task
		if(identifier.empty())
			throw GeneralException(name + " may not be empty");
		if(std::string(allowedIdentifierCharacters.begin(), allowedIdentifierCharacters.end()-10).find(identifier[0]) == std::string::npos)
			throw GeneralException(name + " may only begin with a letter or an underscore, not like '" + identifier + "' with '" + std::string(1, identifier[0]) + "'");
		if(identifier.find_first_not_of(allowedIdentifierCharacters) != std::string::npos)
			throw GeneralException(name + " may only contain letters, numbers or underscores, thus '" + identifier + "' is invalid");
	}

	void ProjectManager::validateFile(const fs::path& filepath, fs::file_type type)
	{
		const std::string typeString(Utilities::fileTypeToString(type));
		bool hasCorrectType = false;
	
		if(!fs::exists(filepath))
			throw GeneralException(typeString + " '" + filepath.string() + "' is missing");
		switch(type)
		{
			case fs::file_type::regular_file	: hasCorrectType = fs::is_regular_file(filepath); break;
			case fs::file_type::directory_file	: hasCorrectType = fs::is_directory(filepath); break;
			default								: break;
		}
		if(!hasCorrectType)
			throw GeneralException("'" + filepath.string() + "' needs to be a " + typeString);
	}

	void ProjectManager::validateRequiredDirectories(const ProjectManager::RequiredDirectoriesList& reqDirs, const fs::path& dirPrefix)
	{
		for(auto& f : reqDirs)
			validateFile(dirPrefix / f, fs::file_type::directory_file);
	}

	void ProjectManager::validateRequiredFiles(const ProjectManager::RequiredFilesList& reqFiles, const fs::path& dirPrefix)
	{
		for(auto& f : reqFiles)
			validateFile(dirPrefix / f.first, fs::file_type::regular_file);
	}

	void ProjectManager::validateAllowedFileExtensions(const ProjectManager::AllowedFileExtensionsList& allFileExts, const fs::path& dir)
	{
		for(fs::directory_entry& e : fs::directory_iterator(dir))
		{
			if(!fs::is_regular_file(e.path()))
				throw GeneralException("'" + e.path().string() + "' needs to be a " + Utilities::fileTypeToString(fs::file_type::regular_file));
			if(std::find(allFileExts.begin(), allFileExts.end(), e.path().extension()) == allFileExts.end())
			{
				std::string allowedConcat;																			//is there an easy standard library function for concatenating all strings in a vector? std::accumulate does not allow a separator...
				for(auto& s : allFileExts)
					allowedConcat += s + " ";
				throw GeneralException("illegal file extension '" + e.path().extension().string() + "' in '" + e.path().string() + "', only the following are allowed: " + allowedConcat);
			}
		}
	}

	void ProjectManager::validateObject(const std::string& objName, const fs::path& dirPrefix)
	{
		fs::path objBasePath(dirPrefix / "objects" / objName);

		if(!fs::exists(objBasePath))
			throw GeneralException("object '" + objName + "' does not exist in '" + objBasePath.string() + "'");
		if(!fs::is_directory(objBasePath))
			throw GeneralException("'" + objBasePath.string() + "' needs to be a " + Utilities::fileTypeToString(fs::file_type::directory_file));
	
		validateIdentifier("object name", objName);
		validateRequiredDirectories(requiredObjectDirectories, objBasePath);
		validateRequiredFiles(requiredObjectFiles, objBasePath);
	
		validateAllowedFileExtensions(allowedCostumeFileExtensions, objBasePath / "costumes");
		validateAllowedFileExtensions(allowedScriptFileExtensions,  objBasePath / "scripts");
		validateAllowedFileExtensions(allowedSoundFileExtensions,   objBasePath / "sounds");
	}
	
	
	
	
	
	std::shared_ptr<Object> ProjectManager::loadObject(const std::string& objName, const fs::path& dirPrefix)		//object's existance is guaranteed because of previous call to "validate"
	{
		fs::path				objBasePath(dirPrefix / "objects" / objName);
		std::shared_ptr<Object>	ret = std::make_shared<Object>(objName);
		
		for(fs::directory_entry& e : fs::directory_iterator(objBasePath / "costumes"))
			ret->addCostume(std::make_shared<Costume>(e.path()));
		for(fs::directory_entry& e : fs::directory_iterator(objBasePath / "sounds"))
			ret->addSound(std::make_shared<Sound>(e.path()));
		
		return ret;
	}





	ProjectManager::ProjectManager()
	{

	}

	ProjectManager::ProjectManager(const fs::path& newPathPrefix, const std::string& newProjectName) : pathPrefix(newPathPrefix), projectName(newProjectName)
	{

	}

	void ProjectManager::initialize()
	{
		fs::path projectDir(projectName);
		if(fs::exists(projectName))
			throw GeneralException("'" + projectName + "' already exists as a " + Utilities::fileTypeToString(projectName));
	
		try
		{
			fs::create_directory(projectDir);
			createRequiredDirectories(requiredFirstLevelDirectories, projectDir);
			addObject("stage", projectDir, false);
			createRequiredFiles(requiredFirstLevelFiles, projectDir);
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
	
		validate(projectDir);
		std::cout << "successfully created project tree for '" + projectName + "'" << std::endl;
	}

	void ProjectManager::addObject(const std::string& objName, const fs::path& dirPrefix, bool validateAll)			//current path needs to be project's first level
	{
		fs::path objBasePath(dirPrefix / "objects" / objName);
		if(fs::exists(objBasePath))
			throw GeneralException("'" + objBasePath.string() + "' already exists as a " + Utilities::fileTypeToString(objBasePath));
	
		try
		{
			createRequiredDirectories(requiredObjectDirectories, objBasePath);
			createRequiredFiles(requiredObjectFiles, objBasePath);
		}
		catch(const fs::filesystem_error& e)
			{ throw GeneralException(std::string("file system error: ") + e.what()); }
	
		if(validateAll)
			validate(dirPrefix);
		else
			validateObject(objName, dirPrefix);
		std::cout << "successfully added object '" + objName + "' to project '" + projectName + "'" << std::endl;
	}

	void ProjectManager::validate(const fs::path& dirPrefix)														//for this function, dirPrefix / fs::current_path needs to be the project tree's first level, i.e. 'bin/' and 'objects/' need to be directly accessible
	{
		//check that project name is valid
		validateIdentifier("project name", projectName);

		//check that required directories and files exist
		std::string objectName;
		try
		{
			validateRequiredDirectories(requiredFirstLevelDirectories, dirPrefix);
			for(fs::directory_entry& e : fs::directory_iterator(dirPrefix / "objects"))
				validateObject(e.path().filename().string(), dirPrefix);
			validateObject("stage", dirPrefix);																		//the "stage" object HAS TO exist
			validateRequiredFiles(requiredFirstLevelFiles, dirPrefix);
		}
		catch(const GeneralException& e)
			{ throw GeneralException(std::string("invalid project tree: ") + e.what()); }
	}

	void ProjectManager::build(const fs::path& dirPrefix)
	{
		std::vector<std::shared_ptr<Object>> objects;
	
		validate();
		for(fs::directory_entry& e : fs::directory_iterator(dirPrefix / "objects"))
		{
			objects.push_back(loadObject(e.path().filename().string(), dirPrefix));									//TODO: do not allow double names (currently not possible anyway, because costumes and sounds both have just one available file extension)
			std::cout << "Object '" << objects.back()->getName() << "':\n";
			std::cout << "    " << objects.back()->getCostumes().size() << " costume(s):\n";
			for(auto& c : objects.back()->getCostumes())
				std::cout << "        '" << c->getName() << "' at " << c->getResourcePath() << ", size: " << c->getWidth() << " x " << c->getHeight() << "\n";
			std::cout << "    " << objects.back()->getSounds().size() << " sound(s):\n";
			for(auto& s : objects.back()->getSounds())
				std::cout << "        '" << s->getName() << "' at " << s->getResourcePath() << ", sampleCount: " << s->getSampleCount() << ", rate: " << s->getRate() << "\n";
			std::cout << std::endl;
		}
	}

	void ProjectManager::clean(const fs::path& dirPrefix)
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

	void ProjectManager::setProjectPath(const std::string& newProjectPath)
	{
		fs::path projPath(newProjectPath);
		pathPrefix = projPath.parent_path();
		projectName = projPath.filename().string();
	}

	void ProjectManager::setPathPrefix(const fs::path& newPathPrefix)
	{
		pathPrefix = newPathPrefix;
	}

	void ProjectManager::setProjectName(const std::string& newProjectName)
	{
		projectName = newProjectName;
	}
}
