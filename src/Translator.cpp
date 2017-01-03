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
		void translate(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
		{
			using namespace rapidjson;
			
			Value command(kArrayType), commandContents(kArrayType), commandContentsName(kArrayType), commandContentsAction(kArrayType);
			
			valDest.SetArray();
			commandContentsName.PushBack("whenGreenFlag", alloc);
			commandContentsAction.PushBack("wait:elapsed:from:", alloc);
			commandContentsAction.PushBack(1, alloc);
			commandContents.PushBack(commandContentsName, alloc);
			commandContents.PushBack(commandContentsAction, alloc);
			command.PushBack(14, alloc);
			command.PushBack(14, alloc);
			command.PushBack(commandContents, alloc);
			valDest.PushBack(command, alloc);
		}
	}
}
