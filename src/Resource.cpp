/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Resource.cpp
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



#include "Resource.hpp"



namespace fs = boost::filesystem;

namespace sc
{
	Resource::Resource() : resourceID(-1)
	{
	
	}
	
	void Resource::loadFromPath(const fs::path& newResourcePath)
	{
		resourceID = -1;
		resourcePath = newResourcePath;
		Utilities::validateFile(resourcePath, fs::file_type::regular_file);
		name = resourcePath.stem().string();
		md5Sum = Utilities::getFileMD5Sum(resourcePath);
	}
	
	void Resource::buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
	{
	
	}
	
	const std::string& Resource::getName()
	{
		return name;
	}
	
	int Resource::getResourceID()
	{
		return resourceID;
	}
	
	int Resource::getResourceIndex()
	{
		return resourceIndex;
	}
	
	const fs::path& Resource::getResourcePath()
	{
		return resourcePath;
	}
	
	const std::string& Resource::getMD5Sum()
	{
		return md5Sum;
	}
	
	void Resource::setName(const std::string& newName)
	{
		name = newName;
	}
	
	void Resource::setResourceID(int newResourceID)
	{
		resourceID = newResourceID;
	}
	
	void Resource::setResourceIndex(int newResourceIndex)
	{
		resourceIndex = newResourceIndex;
	}
}
