/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ScratchCodeTranslator.hpp
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



#include <cstdlib>
#include <string>
#include <fstream>
#include <memory>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <ZipLib/ZipFile.h>
#include <ast/AST.hpp>



namespace ScratchCodeTranslator
{
	namespace detail
	{
		void													writeDocumentToFile(rapidjson::Document& doc, const std::string& filename);
	}

	void														translate(std::shared_ptr<ast::StatementList> input, const std::string& filename);
}
