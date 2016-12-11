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



namespace sc
{
	namespace Utilities
	{
		std::string getDocumentString(rapidjson::Document& doc)
		{
			using namespace rapidjson;
		
			StringBuffer buffer;
			PrettyWriter<StringBuffer> writer(buffer);
			doc.Accept(writer);
			
			return buffer.GetString();
		}
	
		void writeDocumentToFile(rapidjson::Document& doc, const std::string& filename)
		{
			std::ofstream outFile(filename);
			if(!outFile)
				throw ScratchCodeException("unable to open JSON output file \"" + filename + "\"");
			outFile << getDocumentString(doc);
			outFile.close();
		}
	}
}
