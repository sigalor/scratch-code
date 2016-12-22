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
#include <type_traits>

#include <boost/filesystem.hpp>
#include <ZipLib/ZipFile.h>

#include "Translator.hpp"
#include "GeneralException.hpp"
#include "Object.hpp"
#include "Resource.hpp"
#include "Costume.hpp"
#include "Sound.hpp"



namespace sc
{
	class ProjectManager
	{
		public:
			using RequiredDirectoriesList = std::vector<boost::filesystem::path>;
			using RequiredFilesList = std::vector<std::pair<boost::filesystem::path, std::function<void(const boost::filesystem::path&, ProjectManager*)>>>;

		private:
			static const RequiredDirectoriesList					requiredFirstLevelDirectories, requiredObjectDirectories;
			static const RequiredFilesList							requiredFirstLevelFiles, requiredObjectFiles;
		
			boost::filesystem::path									pathPrefix, projectPath;
			std::string												projectName;
			std::shared_ptr<Object>									stageObject;
			std::vector<std::shared_ptr<Object>>					objects;
		
			void													createRequiredDirectories(const RequiredDirectoriesList& reqDirs, const boost::filesystem::path& dirPrefix="");
			void													createRequiredFiles(const RequiredFilesList& reqFiles, const boost::filesystem::path& dirPrefix="");
			void													validateRequiredDirectories(const RequiredDirectoriesList& reqDirs, const boost::filesystem::path& dirPrefix="");
			void													validateRequiredFiles(const RequiredFilesList& reqFiles, const boost::filesystem::path& dirPrefix="");
			
			void													loadAllObjects();
			std::shared_ptr<Object>									getObject(const std::string& objName);
			
			template<typename T>
			typename std::enable_if_t<std::is_base_of<Resource, T>::value, void>
			buildObjectResourceList(const std::vector<std::shared_ptr<T>>& resourceList, const boost::filesystem::path& dirPrefix="")
			{
				for(auto it = resourceList.begin(); it != resourceList.end(); ++it)
				{
					auto i = std::distance(resourceList.begin(), it);
					auto p = (*it)->getResourcePath();
					boost::filesystem::copy(p, projectPath / "gen" / (std::to_string(i) + p.extension().string()));
				}
			}
			void													buildProjectJSON(std::shared_ptr<Costume> penLayer, rapidjson::Document& docDest);
			
		public:
			ProjectManager();
			ProjectManager(const boost::filesystem::path& newPathPrefix, const std::string& newProjectName);
		
			void													initialize();
			void													addObject(const std::string& objName, const boost::filesystem::path& objPath, Object::Type objType=Object::Type::Generic);
			void													addObject(const std::string& objName, Object::Type objType=Object::Type::Generic);
			void													validate();
			void													build();
			void													clean();
			const boost::filesystem::path&							getPathPrefix();
			const std::string&										getProjectName();
			void													setProjectPath(const boost::filesystem::path& newProjectPath);
			void													setPathPrefix(const boost::filesystem::path& newPathPrefix);
			void													setProjectName(const std::string& newProjectName);
	};
}
