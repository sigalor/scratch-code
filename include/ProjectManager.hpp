/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ProjectManager.hpp
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



#pragma once



#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#include <boost/filesystem.hpp>

#include "ScratchCodeTranslator.hpp"
#include "ScratchCodeException.hpp"



class ProjectManager
{
	public:
		using RequiredFilesList = std::vector<std::pair<boost::filesystem::file_type, std::string>>;
		using AllowedFileExtensionsList = std::vector<std::string>;

	private:
		static const std::string								allowedIdentifierCharacters;
		static const RequiredFilesList							requiredFirstLevelFiles;
		static const RequiredFilesList							requiredObjectFiles;
		static const AllowedFileExtensionsList					allowedCostumeFileExtensions;
		static const AllowedFileExtensionsList					allowedSoundFileExtensions;
		
		std::string												pathPrefix, projectName;
		std::vector<std::string>								objectNames;
	
		const std::string										fileTypeToString(boost::filesystem::file_type fileType);
		void													validateIdentifier(const std::string& name, const std::string& identifier);
		void													validateRequiredFiles(const RequiredFilesList& reqFiles, const std::string& dirPrefix="");
		void													validateAllowedFileExtensions(const AllowedFileExtensionsList& allFileExt, const std::string& dir=".");
	
	public:
		ProjectManager();
		ProjectManager(const std::string& newPathPrefix, const std::string& newProjectName);
		
		void													initialize();
		void													validate();
		void													build();
		void													clean();
		const std::string&										getPathPrefix();
		const std::string&										getProjectName();
		void													setProjectPath(const std::string& newProjectPath);
		void													setPathPrefix(const std::string& newPathPrefix);
		void													setProjectName(const std::string& newProjectName);
};
