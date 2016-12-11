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
			[](const fs::path& filepath, ProjectManager* projMgr) -> std::string
			{
				using namespace rapidjson;
	
				Document doc;
				Document::AllocatorType& alloc = doc.GetAllocator();
		
				doc.SetObject();
				doc.AddMember("user", "your_username", alloc);
				doc.AddMember("title", Value(projMgr->getProjectName().c_str(), alloc), alloc);						//cannot use .c_str() directly, because the resulting char* would not have safe life cycle, from https://github.com/miloyip/rapidjson/issues/738#issuecomment-247340768
		
				return Utilities::getDocumentString(doc);
			}
		}
	};

	const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedCostumeFileExtensions	= { ".png", ".svg" };
	const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedScriptFileExtensions		= { ".sc" };
	const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedSoundFileExtensions		= { ".wav" };



	const std::string ProjectManager::fileTypeToString(fs::file_type fileType)
	{
		switch(fileType)
		{
			case fs::file_type::regular_file	: return "regular file";
			case fs::file_type::directory_file	: return "directory";
			case fs::file_type::symlink_file	: return "symlink";
			case fs::file_type::block_file		: return "block file";
			case fs::file_type::character_file	: return "character file";
			case fs::file_type::fifo_file		: return "fifo file";
			case fs::file_type::socket_file		: return "socket file";
			default								: return "(unknown file type)";
		}
	}

	const std::string ProjectManager::fileTypeToString(const boost::filesystem::path& filepath)
	{
		return fileTypeToString(fs::status(filepath).type());
	}





	void ProjectManager::createFile(const fs::path& filepath, const std::string& contents)
	{
		std::ofstream f(filepath.string().c_str());
		if(!f)
			throw ScratchCodeException("cannot open " + fileTypeToString(fs::file_type::regular_file) + " '" + filepath.string() + "' for writing");
		if(!contents.empty())
			f << contents;
		f.close();
	}

	void ProjectManager::createRequiredDirectories(const RequiredDirectoriesList& reqDirs, const fs::path& dirPrefix)
	{
		for(auto& f : reqDirs)
			fs::create_directories(dirPrefix / f);																		//fs::create_directories acts like "mkdir -p", i.e. it creates missing parents as well
	}

	void ProjectManager::createRequiredFiles(const ProjectManager::RequiredFilesList& reqFiles, const fs::path& dirPrefix)
	{
		for(auto& f : reqFiles)
		{
			fs::path currPath(dirPrefix / f.first);
			fs::create_directories(currPath.parent_path());
			createFile(currPath, f.second(currPath, this));															//the pair's second element is a function containing the building instructions for the specified file and returns the string that will be written to that file
		}
	}





	void ProjectManager::validateIdentifier(const std::string& name, const std::string& identifier)
	{
		//trying to match a regex like [_A-Za-z][_A-Za-z0-9]* would be possible, but the std::regex library is way too big for such a simple task
		if(identifier.empty())
			throw ScratchCodeException(name + " may not be empty");
		if(std::string(allowedIdentifierCharacters.begin(), allowedIdentifierCharacters.end()-10).find(identifier[0]) == std::string::npos)
			throw ScratchCodeException(name + " may only begin with a letter or an underscore, not like '" + identifier + "' with '" + std::string(1, identifier[0]) + "'");
		if(identifier.find_first_not_of(allowedIdentifierCharacters) != std::string::npos)
			throw ScratchCodeException(name + " may only contain letters, numbers or underscores, thus '" + identifier + "' is invalid");
	}

	void ProjectManager::validateFile(const fs::path& filepath, fs::file_type type)
	{
		const std::string typeString(fileTypeToString(type));
		bool hasCorrectType = false;
	
		if(!fs::exists(filepath))
			throw ScratchCodeException(typeString + " '" + filepath.string() + "' is missing");
		switch(type)
		{
			case fs::file_type::regular_file	: hasCorrectType = fs::is_regular_file(filepath); break;
			case fs::file_type::directory_file	: hasCorrectType = fs::is_directory(filepath); break;
			default								: break;
		}
		if(!hasCorrectType)
			throw ScratchCodeException("'" + filepath.string() + "' needs to be a " + typeString);
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

	void ProjectManager::validateAllowedFileExtensions(const ProjectManager::AllowedFileExtensionsList& allFileExt, const fs::path& dir)
	{
		for(fs::directory_entry& e : fs::directory_iterator(dir))
		{
			if(!fs::is_regular_file(e.path()))
				throw ScratchCodeException("'" + e.path().string() + "' needs to be a " + fileTypeToString(fs::file_type::regular_file));
			if(std::find(allFileExt.begin(), allFileExt.end(), e.path().extension()) == allFileExt.end())
			{
				std::string allowedConcat;																			//is there an easy standard library function for concatenating all strings in a vector? std::accumulate does not allow a separator...
				for(auto& s : allFileExt)
					allowedConcat += s + " ";
				throw ScratchCodeException("illegal file extension '" + e.path().extension().string() + "' in '" + e.path().string() + "', only the following are allowed: " + allowedConcat);
			}
		}
	}

	void ProjectManager::validateObject(const std::string& objName, const fs::path& dirPrefix)
	{
		fs::path objDir(dirPrefix / "objects" / objName);

		if(!fs::exists(objDir))
			throw ScratchCodeException("object '" + objName + "' does not exist in '" + objDir.string() + "'");
		if(!fs::is_directory(objDir))
			throw ScratchCodeException("'" + objDir.string() + "' needs to be a " + fileTypeToString(fs::file_type::directory_file));
	
		validateIdentifier("object name", objName);
		validateRequiredDirectories(requiredObjectDirectories, objDir);
	
		validateAllowedFileExtensions(allowedCostumeFileExtensions, objDir / "costumes");
		validateAllowedFileExtensions(allowedScriptFileExtensions,  objDir / "scripts");
		validateAllowedFileExtensions(allowedSoundFileExtensions,   objDir / "sounds");
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
			throw ScratchCodeException("'" + projectName + "' already exists as a " + fileTypeToString(projectName));
	
		try
		{
			fs::create_directory(projectDir);
			createRequiredDirectories(requiredFirstLevelDirectories, projectDir);
			addObject("stage", projectDir);
			createRequiredFiles(requiredFirstLevelFiles, projectDir);
		}
		catch(const fs::filesystem_error& e)
			{ throw ScratchCodeException(std::string("file system error: ") + e.what()); }
	
		validate(projectDir);
		std::cout << "successfully created project tree for '" + projectName + "'" << std::endl;
	}

	void ProjectManager::addObject(const std::string& objName, const fs::path& dirPrefix)							//current path needs to be project's first level
	{
		fs::path objBasePath(dirPrefix / "objects" / objName);
		if(fs::exists(objBasePath))
			throw ScratchCodeException("'" + objBasePath.string() + "' already exists as a" + fileTypeToString(objBasePath));
	
		try
			{ createRequiredDirectories(requiredObjectDirectories, objBasePath); }
		catch(const fs::filesystem_error& e)
			{ throw ScratchCodeException(std::string("file system error: ") + e.what()); }
	
		validate(dirPrefix);
		std::cout << "successfully added object '" + objName + "' to project '" + projectName + "'" << std::endl;
	}

	void ProjectManager::validate(const fs::path& dirPrefix)														//for this function, dirPrefix / fs::current_path needs to be the project tree's first level, i.e. 'bin/' and 'objects/' need to be directly accessible
	{
		//check that project name is valid
		validateIdentifier("project name", projectName);

		//check that required first level files exist
		std::string objectName;
		try
		{
			validateRequiredDirectories(requiredFirstLevelDirectories, dirPrefix);
			for(fs::directory_entry& e : fs::directory_iterator(dirPrefix / "objects"))
				validateObject(e.path().filename().string(), dirPrefix);
		}
		catch(const ScratchCodeException& e)
			{ throw ScratchCodeException(std::string("invalid project tree: ") + e.what()); }
		std::cout << "project tree for '" + projectName + "' is valid" << std::endl;
	}

	void ProjectManager::build()
	{
		validate();
		std::cout << "Path prefix:  " << pathPrefix << std::endl;
		std::cout << "Project name: " << projectName << std::endl;
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
