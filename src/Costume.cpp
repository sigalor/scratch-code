/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Costume.cpp
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



#include "Costume.hpp"



namespace fs = boost::filesystem;

namespace sc
{
	Costume::Costume()
	{
	
	}
	
	Costume::Costume(const fs::path& newResourcePath)
	{
		loadFromPath(newResourcePath);
	}
	
	void Costume::loadFromPath(const fs::path& newResourcePath)
	{
		std::string fileExt;
		
		Resource::loadFromPath(newResourcePath);																	//when this function does not throw a GeneralException, the file is guaranteed to exist and be readable, as Utilities::getFileMD5Sum checked that
		fileExt = resourcePath.extension().string();
		if(fileExt != ".png")
			throw GeneralException("unknown costume file extension: '" + fileExt + "'");
		
		try
		{
			if(fileExt == ".png")																					//from http://www.libpng.org/pub/png/book/chapter13.html
			{
				FILE*		inpFile = fopen(resourcePath.string().c_str(), "rb");
				uint8_t		signature[8];
				png_structp	pngPtr = nullptr;
				png_infop	infoPtr = nullptr;
				
				//read signature
				fread(signature, sizeof(uint8_t), 8, inpFile);
				if(!png_check_sig(signature, 8))
					throw GeneralException("bad signature");
				
				//create png read struct
				pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
				if(pngPtr == nullptr)
					throw GeneralException("unable to create PNG read struct");
	
				//create png info struct
				infoPtr = png_create_info_struct(pngPtr);
				if(infoPtr == nullptr)
				{
					png_destroy_read_struct(&pngPtr, nullptr, nullptr);
					throw GeneralException("unable to create PNG info struct");
				}
				
				//set up error handling
				if(setjmp(png_jmpbuf(pngPtr)))
				{
					png_destroy_read_struct(&pngPtr, &infoPtr, nullptr);
					throw GeneralException("unknown error");
				}
				
				//read image information
				png_init_io(pngPtr, inpFile);
				png_set_sig_bytes(pngPtr, 8);
				png_read_info(pngPtr, infoPtr);
				
				//get width and height from IHDR chunk
				png_get_IHDR(pngPtr, infoPtr, &width, &height, &bitDepth, &colorType, nullptr, nullptr, nullptr);
				
				fclose(inpFile);
			}
		}
		catch(const GeneralException& e)
		{
			throw GeneralException("invalid '" + fileExt + "' file: " + e.what());
		}
	}
	
	uint32_t Costume::getWidth()
	{
		return width;
	}
	
	uint32_t Costume::getHeight()
	{
		return height;
	}
	
	int Costume::getBitDepth()
	{
		return bitDepth;
	}
	
	int Costume::getColorType()
	{
		return colorType;
	}
}
