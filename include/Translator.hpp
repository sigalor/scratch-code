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
#include <utility>
#include <unordered_map>

#include <boost/variant.hpp>
#include <rapidjson/document.h>
#include <ast/AST.hpp>

#include "Driver.hpp"
#include "OpcodeAliases.hpp"
#include "Utilities.hpp"
#include "GeneralException.hpp"
#include "Object.hpp"



namespace sc
{
	class Object;
	class Driver;
	namespace OpcodeAliases { class OpcodeAlias; }

	class Translator
	{
		private:
			Object*												targetObject;
			std::shared_ptr<Driver>								parsingDriver;
			rapidjson::Document::AllocatorType&					alloc;
			std::unordered_map<std::shared_ptr<ast::FunctionDefinition>, std::string> functionSignatures;
			
			void												validateFunctionCall(std::shared_ptr<ast::FunctionCall> input, const OpcodeAliases::OpcodeAlias& opcodeAlias);
			
			void												translateStatement(std::shared_ptr<ast::Statement> input, rapidjson::Value& valDest);
			void												translateFunctionDefinition(std::shared_ptr<ast::FunctionDefinition> input, rapidjson::Value& valDest);
			void												translateValue(std::shared_ptr<ast::Value> input, rapidjson::Value& valDest);
			void												translateRValue(std::shared_ptr<ast::RValue> input, rapidjson::Value& valDest);
			void												translateRValueValue(std::shared_ptr<ast::RValueValue> input, rapidjson::Value& valDest);
			void												translateFunctionCall(std::shared_ptr<ast::FunctionCall> input, rapidjson::Value& valDest);
			void												translateControlFlowStatement(std::shared_ptr<ast::ControlFlowStatement> input, rapidjson::Value& valDest);
			void												translateConditional(std::shared_ptr<ast::Conditional> input, rapidjson::Value& valDest);
			void												translateStatementList(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, bool append=false);
		
		public:
			Translator(Object* newTargetObject, std::shared_ptr<Driver> newParsingDriver, rapidjson::Document::AllocatorType& newAlloc);
			void												translate(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest);
	};
}
