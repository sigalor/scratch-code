/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Utilities.hpp
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



#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include <boost/filesystem.hpp>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <png.h>
#include <openssl/md5.h>

#include "ScratchCodeException.hpp"



namespace sc
{
	namespace Utilities
	{
		const std::string										fileTypeToString(boost::filesystem::file_type fileType);
		const std::string										fileTypeToString(const boost::filesystem::path& filepath);
		void													createFile(const boost::filesystem::path& filepath, const std::string& contents="");
		
		std::string												getDocumentString(rapidjson::Document& doc, bool pretty);
		void													writeDocumentToFile(const boost::filesystem::path& filepath, rapidjson::Document& doc);
		
		void													writePlainPNGToFile(const boost::filesystem::path& filepath, uint32_t width, uint32_t height, uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA);
		
		std::string												md5DigestToString(const uint8_t* digest);
		std::string												getMD5Sum(const std::string& data);
		std::string												getFileMD5Sum(const boost::filesystem::path& filepath);
	}
}
