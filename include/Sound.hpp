/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Sound.hpp
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
#include <cstring>
#include <cinttypes>

#include <boost/filesystem.hpp>

#include "Resource.hpp"
#include "GeneralException.hpp"



namespace sc
{
	namespace WAVFile
	{
		typedef struct __attribute__ ((__packed__))																	//__packed__, because 'fread' is used to directly write into this struct
		{
			char     chunkID[4];
			uint32_t chunkSize;
			char     riffType[4];
		} RIFFSection;

		typedef struct __attribute__ ((__packed__))
		{
			char     formatID[4];
			uint32_t formatSize;
			uint16_t formatTag;
			uint16_t channels;
			uint32_t samplesPerSec;
			uint32_t avgBytesPerSec;
			uint16_t blockAlign;
			uint16_t bitsPerSample;
		} FormatSection;
		
		typedef struct __attribute__ ((__packed__))																	//pointer to the beginning of an array of 'frames' would come at the end, but it's not needed
		{
			char     dataID[4];
			uint32_t dataSize;
		} DataSection;
	}

	class Sound : public Resource
	{
		private:
			std::size_t											sampleCount, rate;
	
		public:
			Sound();
			Sound(const boost::filesystem::path& newResourcePath);
			
			void												loadFromPath(const boost::filesystem::path& newResourcePath);
			void												buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
			std::size_t											getSampleCount();
			std::size_t											getRate();
	};
}
