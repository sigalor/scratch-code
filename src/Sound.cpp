/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Sound.cpp
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



#include "Sound.hpp"



namespace fs = boost::filesystem;

namespace sc
{
	Sound::Sound()
	{
	
	}
	
	Sound::Sound(const fs::path& newResourcePath)
	{
		loadFromPath(newResourcePath);
	}
	
	void Sound::loadFromPath(const fs::path& newResourcePath)
	{
		std::string fileExt;
		
		Resource::loadFromPath(newResourcePath);																	//when this function does not throw a GeneralException, the file is guaranteed to exist and be readable, as Utilities::getFileMD5Sum checked that
		fileExt = resourcePath.extension().string();
		if(fileExt != ".wav")
			throw GeneralException("unknown sound file extension: '" + fileExt + "'");
		
		try
		{
			if(fileExt == ".wav")
			{
				FILE*					inpFile = fopen(resourcePath.string().c_str(), "r");
				WAVFile::RIFFSection	riffSection;
				WAVFile::FormatSection	formatSection;
				WAVFile::DataSection	dataSection;
				
				//read RIFF section
				fread(&riffSection, sizeof(WAVFile::RIFFSection), 1, inpFile);
				if(strncmp(riffSection.chunkID, "RIFF", 4) != 0)
					throw GeneralException("no 'RIFF' found");
				if(strncmp(riffSection.riffType, "WAVE", 4) != 0)
					throw GeneralException("no 'WAVE' found");
				
				//read format section
				fread(&formatSection, sizeof(WAVFile::FormatSection), 1, inpFile);
				if(strncmp(formatSection.formatID, "fmt ", 4) != 0)
					throw GeneralException("no format section found");
				
				//read data section
				fread(&dataSection, sizeof(WAVFile::DataSection), 1, inpFile);
				if(strncmp(dataSection.dataID, "data", 4) != 0)
					throw GeneralException("no data section found");
				
				//calculate wanted variables
				sampleCount = dataSection.dataSize / formatSection.blockAlign;										//'dataSize' is in bytes; 'blockAlign' specifies the size of each frame in bytes; the number of frames (i.e. samples) is needed
				rate = formatSection.samplesPerSec;
				
				fclose(inpFile);
			}
		}
		catch(const GeneralException& e)
		{
			throw GeneralException("invalid '" + fileExt + "' file: " + e.what());
		}
	}
	
	std::size_t Sound::getSampleCount()
	{
		return sampleCount;
	}
	
	std::size_t Sound::getRate()
	{
		return rate;
	}
}
