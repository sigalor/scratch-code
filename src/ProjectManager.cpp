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

const std::string ProjectManager::allowedIdentifierCharacters = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

const ProjectManager::RequiredFilesList ProjectManager::requiredFirstLevelFiles =
{
	std::make_pair(fs::file_type::directory_file, "bin"),
	std::make_pair(fs::file_type::directory_file, "objects"),
	std::make_pair(fs::file_type::directory_file, "objects/stage"),
	std::make_pair(fs::file_type::regular_file,   "objects/stage/costumes/penLayer.png"),
	std::make_pair(fs::file_type::regular_file,   "manifest.json")
};

const ProjectManager::RequiredFilesList ProjectManager::requiredObjectFiles =
{
	std::make_pair(fs::file_type::directory_file, "costumes"),
	std::make_pair(fs::file_type::directory_file, "sounds")
};

const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedCostumeFileExtensions = { ".png", ".svg" };
const ProjectManager::AllowedFileExtensionsList ProjectManager::allowedSoundFileExtensions   = { ".wav" };



const std::string ProjectManager::fileTypeToString(fs::file_type fileType)
{
	switch(fileType)
	{
		case fs::file_type::regular_file	: return "regular file";
		case fs::file_type::directory_file	: return "directory";
		default								: return "unknown file type";
	}
}

void ProjectManager::validateIdentifier(const std::string& name, const std::string& identifier)
{
	//regex like [_A-Za-z][_A-Za-z0-9]* would be possible, but the std::regex library is way too big for such a simple task
	if(identifier.empty())
		throw ScratchCodeException(name + " may not be empty");
	if(std::string(allowedIdentifierCharacters.begin(), allowedIdentifierCharacters.end()-10).find(identifier[0]) == std::string::npos)
		throw ScratchCodeException(name + " may only begin with a letter or an underscore, not like '" + identifier + "' with '" + std::string(1, identifier[0]) + "'");
	if(identifier.find_first_not_of(allowedIdentifierCharacters) != std::string::npos)
		throw ScratchCodeException(name + " may only contain letters, numbers or underscores, thus '" + identifier + "' is invalid");
}

void ProjectManager::validateRequiredFiles(const ProjectManager::RequiredFilesList& reqFiles, const std::string& dirPrefix)
{
	bool		hasCorrectFileType;
	std::string	fileTypeString, currPath;

	for(auto& f : reqFiles)
	{
		fileTypeString = fileTypeToString(f.first);
		currPath = (dirPrefix=="" ? "" : (dirPrefix + "/")) + f.second;
		if(!fs::exists(currPath))
			throw ScratchCodeException(fileTypeString + " '" + currPath + "' is missing");
		
		switch(f.first)
		{
			case fs::file_type::regular_file	: hasCorrectFileType = fs::is_regular_file(currPath); break;
			case fs::file_type::directory_file	: hasCorrectFileType = fs::is_directory(currPath); break;
			default								: hasCorrectFileType = false;
		}
		if(!hasCorrectFileType)
			throw ScratchCodeException("'" + currPath + "' needs to be a " + fileTypeString);
	}
}

void ProjectManager::validateAllowedFileExtensions(const ProjectManager::AllowedFileExtensionsList& allFileExt, const std::string& dir)
{
	for(fs::directory_entry& e : fs::directory_iterator(dir))
	{
		if(!fs::is_regular_file(e.path()))
			throw ScratchCodeException("'" + e.path().string() + "' needs to be a " + fileTypeToString(fs::file_type::regular_file));
		if(std::find(allFileExt.begin(), allFileExt.end(), e.path().extension()) == allFileExt.end())
		{
			std::string allowedConcat;																				//is there an easy function for concatenating all strings in a vector? std::accumulate does not allow a separator...
			for(auto& s : allFileExt)
				allowedConcat += s + " ";
			throw ScratchCodeException("illegal file extension '" + e.path().extension().string() + "' in '" + e.path().string() + "', only the following are allowed: " + allowedConcat);
		}
	}
}

ProjectManager::ProjectManager()
{

}

ProjectManager::ProjectManager(const std::string& newPathPrefix, const std::string& newProjectName) : pathPrefix(newPathPrefix), projectName(newProjectName)
{

}

void ProjectManager::initialize()
{

}

void ProjectManager::validate()
{
	//check that project name is valid
	validateIdentifier("project name", projectName);

	//check that required first level files exist
	std::string objectName;
	try
	{
		validateRequiredFiles(requiredFirstLevelFiles);
		for(fs::directory_entry& e : fs::directory_iterator("objects"))
		{
			if(!fs::is_directory(e.path()))
				throw ScratchCodeException("'" + e.path().string() + "' needs to be a " + fileTypeToString(fs::file_type::directory_file));
			
			objectName = e.path().filename().string();
			validateIdentifier("object name", objectName);
			validateRequiredFiles(requiredObjectFiles, "objects/" + objectName);
			
			validateAllowedFileExtensions(allowedCostumeFileExtensions, "objects/" + objectName + "/costumes");
			validateAllowedFileExtensions(allowedSoundFileExtensions,   "objects/" + objectName + "/sounds");
		}
	}
	catch(const ScratchCodeException& e)
		{ throw ScratchCodeException(std::string("invalid project tree: ") + e.what()); }
}

void ProjectManager::build()
{
	validate();
}

void ProjectManager::clean()
{
	validate();
}

const std::string& ProjectManager::getPathPrefix()
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
	pathPrefix = projPath.parent_path().string();
	projectName = projPath.filename().string();
}

void ProjectManager::setPathPrefix(const std::string& newPathPrefix)
{
	pathPrefix = newPathPrefix;
}

void ProjectManager::setProjectName(const std::string& newProjectName)
{
	projectName = newProjectName;
}
