/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Translator.cpp
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



#include "Translator.hpp"



namespace sc
{
	namespace Translator
	{
		void translate(std::shared_ptr<ast::StatementList> input, const std::string& filename)
		{
			using namespace rapidjson;
	
			Document doc;
			Document::AllocatorType& alloc = doc.GetAllocator();
		
			doc.SetObject();
			doc.AddMember("hello", 42, alloc);
		
			Utilities::writeDocumentToFile(doc, filename);
		
		
		
			ZipFile::AddFile("archive.zip", "testsource.sc");
		}
	}
}
