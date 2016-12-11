/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Utilities.cpp
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



#include "Utilities.hpp"



namespace fs = boost::filesystem;

namespace sc
{
	namespace Utilities
	{
		const std::string fileTypeToString(fs::file_type fileType)
		{
			switch(fileType)
			{
				case fs::file_type::regular_file	: return "regular file";
				case fs::file_type::directory_file	: return "directory";
				case fs::file_type::symlink_file	: return "symlink";
				case fs::file_type::block_file		: return "block file";
				case fs::file_type::character_file	: return "character file";
				case fs::file_type::fifo_file		: return "fifo file";
				case fs::file_type::socket_file		: return "socket file";
				default								: return "(unknown file type)";
			}
		}

		const std::string fileTypeToString(const boost::filesystem::path& filepath)
		{
			return fileTypeToString(fs::status(filepath).type());
		}
	
		void createFile(const fs::path& filepath, const std::string& contents)
		{
			std::ofstream f;
			fs::create_directories(filepath.parent_path());
			f.open(filepath.string().c_str());
			if(!f)
				throw ScratchCodeException("cannot open " + fileTypeToString(fs::file_type::regular_file) + " '" + filepath.string() + "' for writing");
			if(!contents.empty())
				f << contents;
			f.close();
		}
		
		
		
		
		
		std::string getDocumentString(rapidjson::Document& doc, bool pretty)
		{
			using namespace rapidjson;
		
			StringBuffer buffer;
			if(pretty)
			{
				PrettyWriter<StringBuffer> writer(buffer);
				doc.Accept(writer);
			}
			else
			{
				Writer<StringBuffer> writer(buffer);
				doc.Accept(writer);
			}
			
			return buffer.GetString();
		}
	
		void writeDocumentToFile(const fs::path& filepath, rapidjson::Document& doc)
		{
			createFile(filepath, getDocumentString(doc, true));
		}
		
		
		
		
		
		void writePlainPNGToFile(const fs::path& filepath, uint32_t width, uint32_t height, uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA)
		{
			FILE*		outFile = nullptr;
			png_structp	pngPtr = nullptr;
			png_infop	infoPtr = nullptr;
			png_byte**	rowPointers = nullptr;
			const int	pixelSize = 4, depth = 8;
	
			try
			{
				//create png write struct
				pngPtr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
				if(pngPtr == nullptr)
					throw ScratchCodeException("unable to create PNG write struct");
	
				//create png info struct
				infoPtr = png_create_info_struct(pngPtr);
				if(infoPtr == nullptr)
				{
					png_destroy_write_struct(&pngPtr, &infoPtr);
					throw ScratchCodeException("unable to create PNG info struct");
				}
	
				//set up error handling
				if(setjmp(png_jmpbuf(pngPtr)))
				{
					png_destroy_write_struct(&pngPtr, &infoPtr);
					throw ScratchCodeException("setjmp failed");
				}
			}
			catch(const ScratchCodeException& e)
				{ throw ScratchCodeException("while creating plain PNG file '" + filepath.string() + "': " + e.what()); }
	
			//set image attributes
			png_set_IHDR(pngPtr, infoPtr, width, height, depth, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	
			//initialize rows of png
			rowPointers = (png_byte**)png_malloc(pngPtr, height * sizeof(png_byte*));
			for(unsigned int y=0; y<height; ++y)
			{
				png_byte* row = (png_byte*)png_malloc(pngPtr, sizeof(uint8_t) * width * pixelSize);
				rowPointers[y] = row;
				for(unsigned int x=0; x<width; ++x)
				{
					*row++ = colorR;
					*row++ = colorG;
					*row++ = colorB;
					*row++ = colorA;
				}
			}
	
			//open output file
			outFile = fopen(filepath.string().c_str(), "wb");
			if(!outFile)
				throw ScratchCodeException("cannot open " + fileTypeToString(fs::file_type::regular_file) + " '" + filepath.string() + "' for writing");
	
			//write image data to output file
			png_init_io(pngPtr, outFile);
			png_set_rows(pngPtr, infoPtr, rowPointers);
			png_write_png(pngPtr, infoPtr, PNG_TRANSFORM_IDENTITY, nullptr);
			fclose(outFile);
	
			//free memory allocated for rows
			for(unsigned int y=0; y<height; ++y)
				png_free(pngPtr, rowPointers[y]);
			png_free(pngPtr, rowPointers);
		}
		
		
		
		
		
		std::string md5DigestToString(const uint8_t* digest)
		{
			char ret[MD5_DIGEST_LENGTH*2 + 1];
			for(size_t i=0; i<MD5_DIGEST_LENGTH; ++i)
				snprintf(&ret[i*2], 3, "%02x", digest[i]);
			return std::string(ret, MD5_DIGEST_LENGTH*2);
		}
		
		std::string getMD5Sum(const std::string& data)
		{
			uint8_t result[MD5_DIGEST_LENGTH];
			MD5((unsigned char*)&data[0], data.size(), result);
			return md5DigestToString(result);
		}
		
		std::string getFileMD5Sum(const fs::path& filepath)
		{
			std::ifstream f(filepath.string().c_str());
			if(!f)
				throw ScratchCodeException("cannot open " + fileTypeToString(fs::file_type::regular_file) + " '" + filepath.string() + "' for reading");
			return getMD5Sum(std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>()));
		}
	}
}
