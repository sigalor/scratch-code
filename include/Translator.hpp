/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Translator.hpp
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
#include <vector>
#include <fstream>
#include <memory>

#include <rapidjson/document.h>
#include <ast/AST.hpp>

#include "Utilities.hpp"



namespace sc
{
	namespace Translator
	{
		/*class BlockTuple
		{
			private:
				std::string										opcode;
				std::vector<rapidjson::Value>					arguments;
			
			public:
				BlockTuple();
				BlockTuple(const std::string& newOpcode);
				
				rapidjson::Value&								addArgument();
		};*/
		
		void													translateStatement(std::shared_ptr<ast::Node> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
		void													translateFunctionDefinition(std::shared_ptr<ast::FunctionDefinition> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
		void													translateValue(std::shared_ptr<ast::Value> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
		void													translateControlFlowStatement(std::shared_ptr<ast::ControlFlowStatement> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
		void													translateConditional(std::shared_ptr<ast::Conditional> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
		void													translateStatementList(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc, bool append=false);
		
		void													translate(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
	}
}
