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
#include <functional>

#include <boost/filesystem.hpp>

#include "Translator.hpp"
#include "GeneralException.hpp"
#include "Object.hpp"
#include "Costume.hpp"
#include "Sound.hpp"



namespace sc
{
	class ProjectManager
	{
		public:
			using RequiredDirectoriesList = std::vector<boost::filesystem::path>;
			using RequiredFilesList = std::vector<std::pair<boost::filesystem::path, std::function<void(const boost::filesystem::path&, ProjectManager*)>>>;
			using AllowedFileExtensionsList = std::vector<std::string>;

		private:
			static const std::string								allowedIdentifierCharacters;
			static const RequiredDirectoriesList					requiredFirstLevelDirectories, requiredObjectDirectories;
			static const RequiredFilesList							requiredFirstLevelFiles, requiredObjectFiles;
			static const AllowedFileExtensionsList					allowedCostumeFileExtensions, allowedScriptFileExtensions, allowedSoundFileExtensions;
		
			boost::filesystem::path									pathPrefix;
			std::string												projectName;
			std::vector<std::string>								objectNames;
		
			void													createRequiredDirectories(const RequiredDirectoriesList& reqDirs, const boost::filesystem::path& dirPrefix="");
			void													createRequiredFiles(const RequiredFilesList& reqFiles, const boost::filesystem::path& dirPrefix="");
		
			void													validateIdentifier(const std::string& name, const std::string& identifier);
			void													validateFile(const boost::filesystem::path& filepath, boost::filesystem::file_type type);
			void													validateRequiredDirectories(const RequiredDirectoriesList& reqDirs, const boost::filesystem::path& dirPrefix="");
			void													validateRequiredFiles(const RequiredFilesList& reqFiles, const boost::filesystem::path& dirPrefix="");
			void													validateAllowedFileExtensions(const AllowedFileExtensionsList& allFileExts, const boost::filesystem::path& dir=".");
			void													validateObject(const std::string& objName, const boost::filesystem::path& dirPrefix="");
			
			std::shared_ptr<Object>									loadObject(const std::string& name, const boost::filesystem::path& dirPrefix);
			
		public:
			ProjectManager();
			ProjectManager(const boost::filesystem::path& newPathPrefix, const std::string& newProjectName);
		
			void													initialize();
			void													addObject(const std::string& objName, const boost::filesystem::path& dirPrefix="", bool validateAll=true);
			void													validate(const boost::filesystem::path& dirPrefix="");
			void													build(const boost::filesystem::path& dirPrefix="");
			void													clean(const boost::filesystem::path& dirPrefix="");
			const boost::filesystem::path&							getPathPrefix();
			const std::string&										getProjectName();
			void													setProjectPath(const std::string& newProjectPath);
			void													setPathPrefix(const boost::filesystem::path& newPathPrefix);
			void													setProjectName(const std::string& newProjectName);
	};
}
