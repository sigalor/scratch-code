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



/*namespace boost::filesystem
{
	path relative_path(const path& from, const path& to)															//from http://stackoverflow.com/a/29221546
	{
		//Start at the root path and while they are the same then do nothing then when they first
		//diverge take the remainder of the two path and replace the entire from path with ".."
		//segments.
		path::const_iterator fromIter = from.begin();
		path::const_iterator toIter = to.begin();

		//Loop through both
		while (fromIter != from.end()  &&  toIter != to.end()  &&  (*toIter) == (*fromIter))
		{
			++toIter;
			++fromIter;
		}

		path finalPath;
		while (fromIter != from.end())
		{
			finalPath /= "..";
			++fromIter;
		}

		while (toIter != to.end())
		{
			finalPath /= *toIter;
			++toIter;
		}

		return finalPath;
	}
}*/

namespace fs = boost::filesystem;

namespace sc
{
	namespace Utilities
	{
		void validateIdentifier(const std::string& description, const std::string& identifier)
		{
			//trying to match a regex like [_A-Za-z][_A-Za-z0-9]* would be possible, but the std::regex library is way too big for such a simple task
			static const std::string allowedIdentifierCharacters = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
			if(identifier.empty())
				throw GeneralException(description + " may not be empty");
			if(std::string(allowedIdentifierCharacters.begin(), allowedIdentifierCharacters.end()-10).find(identifier[0]) == std::string::npos)
				throw GeneralException(description + " may only begin with a letter or an underscore, not like '" + identifier + "' with '" + std::string(1, identifier[0]) + "'");
			if(identifier.find_first_not_of(allowedIdentifierCharacters) != std::string::npos)
				throw GeneralException(description + " may only contain letters, numbers or underscores, thus '" + identifier + "' is invalid");
		}
		
		void validateAllowedFileExtensions(const std::vector<std::string>& allowedFileExts, const fs::path& filepath)
		{
			validateFile(filepath, fs::file_type::regular_file);
			if(std::find(allowedFileExts.begin(), allowedFileExts.end(), filepath.extension()) == allowedFileExts.end())
			{
				std::string afeConcat;																				//is there an easy standard library function for concatenating all strings in a vector? std::accumulate does not allow a separator...
				for(auto& s : allowedFileExts)
					afeConcat += s + " ";
				throw GeneralException("illegal file extension '" + filepath.extension().string() + "' in '" + fs::relative(filepath).string() + "', only the following are allowed: " + afeConcat);
			}
		}
		
		void validateFile(const fs::path& filepath, fs::file_type type)
		{
			const std::string typeString(fileTypeToString(type));
			bool hasCorrectType = false;
	
			if(!fs::exists(filepath))
				throw GeneralException(typeString + " '" + fs::relative(filepath).string() + "' is missing");
			switch(type)
			{
				case fs::file_type::regular_file	: hasCorrectType = fs::is_regular_file(filepath); break;
				case fs::file_type::directory_file	: hasCorrectType = fs::is_directory(filepath); break;
				default								: break;
			}
			if(!hasCorrectType)
				throw GeneralException("'" + fs::relative(filepath).string() + "' needs to be a " + typeString);
		}
		
		
		
		
		
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
				throw GeneralException("cannot open " + fileTypeToString(filepath) + " '" + fs::relative(filepath).string() + "' for writing");
			if(!contents.empty())
				f << contents;
			f.close();
		}
		
		std::string readFile(const fs::path& filepath)
		{
			std::ifstream f;
			validateFile(filepath, fs::file_type::regular_file);
			f.open(filepath.string().c_str());
			if(!f)
				throw GeneralException("cannot open " + fileTypeToString(filepath) + " '" + fs::relative(filepath).string() + "' for reading");
			return std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
		}
		
		void clearDirectory(const fs::path& dirpath)
		{
			validateFile(dirpath, fs::file_type::directory_file);
			fs::remove_all(dirpath);
			fs::create_directory(dirpath);
		}
		
		
			
			
			
		void readDocumentFromFile(const fs::path& filepath, rapidjson::Document& doc)
		{
			using namespace rapidjson;
		
			ParseResult res = doc.Parse<0>(readFile(filepath).c_str());
			if(!res)
				throw GeneralException("JSON in '" + fs::relative(filepath).string() + "' is invalid, offset " + std::to_string(res.Offset()) + ": " + GetParseError_En(res.Code()));
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
					throw GeneralException("unable to create PNG write struct");
	
				//create png info struct
				infoPtr = png_create_info_struct(pngPtr);
				if(infoPtr == nullptr)
				{
					png_destroy_write_struct(&pngPtr, nullptr);
					throw GeneralException("unable to create PNG info struct");
				}
	
				//set up error handling
				if(setjmp(png_jmpbuf(pngPtr)))
				{
					png_destroy_write_struct(&pngPtr, &infoPtr);
					throw GeneralException("unknown error");
				}
			}
			catch(const GeneralException& e)
				{ throw GeneralException("while creating plain PNG file '" + fs::relative(filepath).string() + "': " + e.what()); }
	
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
				throw GeneralException("cannot open " + fileTypeToString(fs::file_type::regular_file) + " '" + fs::relative(filepath).string() + "' for writing");
	
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
			return getMD5Sum(readFile(filepath));
		}
	}
}
