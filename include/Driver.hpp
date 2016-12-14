/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Driver.hpp
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



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

#include <ast/LexerTokenDefinitions.hpp>
#include <ast/StatementList.hpp>

#include "scratch-code.tab.hpp"
#define YY_DECL yy::ScratchCodeParser::symbol_type yylex(sc::Driver& driver)



YY_DECL;
extern int yy_flex_debug;
extern FILE* yyin;

namespace sc
{
	class Driver
	{
		private:
			int													result;
			std::string											filename;
			bool												traceLexing, traceParsing;

		public:
			std::shared_ptr<ast::StatementList>					syntaxTree;
			std::vector<std::shared_ptr<ast::FunctionDefinition>> functionDefinitions;
			std::vector<std::shared_ptr<ast::VariableDefinition>> variableDefinitions;
			std::unordered_map<std::shared_ptr<ast::Node>, yy::location> nodeLocations;								//needed for nodes where the location needs to be stored for later
	
			Driver();
			Driver(bool newTraceLexing, bool newTraceParsing);
			Driver(std::shared_ptr<ast::StatementList> newSyntaxTree);
			Driver(std::shared_ptr<ast::StatementList> newSyntaxTree, bool newTraceLexing, bool newTraceParsing);
			virtual ~Driver();
		
			void												beginLexing();
			void												endLexing();
			int													parse(const std::string& newFilename);
			std::string											locationToString(const yy::location& loc);
			void												handleError(const yy::location& loc, const std::string& message);
			void												handleError(const std::string& message);
			const std::string&									getFilename();
			std::string*										getFilenamePointer();
			int													getResult();
			std::shared_ptr<ast::StatementList>					getSyntaxTree();
			void												setTraceLexing(bool newTraceLexing);
			void												setTraceParsing(bool newTraceParsing);
			std::shared_ptr<ast::FunctionDefinition>			getDefinedFunction(const std::string& name);
			std::shared_ptr<ast::VariableDefinition>			getDefinedVariable(const std::string& name);
			bool												isFunctionDefined(const std::string& name);
			bool												isVariableDefined(const std::string& name);
			void												throwIfDefined(const yy::ScratchCodeParser::location_type& loc, const std::string& name);
	};
}
