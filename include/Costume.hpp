/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Costume.hpp
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
#include <cinttypes>

#include <boost/filesystem.hpp>
#include <png.h>

#include "Resource.hpp"



namespace sc
{
	class Costume : public Resource
	{
		private:
			uint32_t											width, height;
			int													bitDepth, colorType;
			
	
		public:
			Costume();
			Costume(const boost::filesystem::path& newResourcePath);
			
			void												loadFromPath(const boost::filesystem::path& newResourcePath);
			uint32_t											getWidth();
			uint32_t											getHeight();
			int													getBitDepth();
			int													getColorType();
	};
}
