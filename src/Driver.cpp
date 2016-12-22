/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Driver.cpp
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



#include "Driver.hpp"



namespace fs = boost::filesystem;

namespace sc
{
	Driver::Driver() : result(0), traceLexing(false), traceParsing(false) { }
	Driver::Driver(bool newTraceLexing, bool newTraceParsing) : result(0), traceLexing(newTraceLexing), traceParsing(newTraceParsing) { }
	Driver::Driver(std::shared_ptr<ast::StatementList> newSyntaxTree) : result(0), traceLexing(false), traceParsing(false), syntaxTree(newSyntaxTree) { }
	Driver::Driver(std::shared_ptr<ast::StatementList> newSyntaxTree, bool newTraceLexing, bool newTraceParsing) : result(0), traceLexing(newTraceLexing), traceParsing(newTraceParsing), syntaxTree(newSyntaxTree) { }
	Driver::~Driver() { }

	void Driver::beginLexing()
	{
		yy_flex_debug = traceLexing;
		if(filepath.empty()  ||  filepath == "-")
			yyin = stdin;
		else
		{
			Utilities::validateFile(filepath, fs::file_type::regular_file);
			if(!(yyin = fopen(filepath.c_str(), "r")))
				throw GeneralException("cannot open " + fs::relative(filepath).string() + " for reading: " + strerror(errno));
		}
	}

	void Driver::endLexing()
	{
		fclose(yyin);
	}

	int Driver::parse(const fs::path& newFilepath)
	{
		yy::ScratchCodeParser parser(*this);

		filepath = newFilepath;
		beginLexing();
		parser.set_debug_level(traceParsing);
		result = parser.parse();
		endLexing();
	
		return result;
	}

	std::string Driver::locationToString(const yy::location& loc)
	{
		return fs::relative(filepath).string() + ":" + std::to_string(loc.begin.line) + ":" + std::to_string(loc.begin.column);
	}

	void Driver::handleError(const yy::location& loc, const std::string& message)
	{
		std::cerr << locationToString(loc) << ": " << message << std::endl;
	}

	void Driver::handleError(const std::string& message)
	{
		std::cerr << message << std::endl;
	}

	const fs::path& Driver::getFilepath()
	{
		return filepath;
	}

	int Driver::getResult()
	{
		return result;
	}

	std::shared_ptr<ast::StatementList> Driver::getSyntaxTree()
	{
		return syntaxTree;
	}

	void Driver::setTraceLexing(bool newTraceLexing)
	{
		traceLexing = newTraceLexing;
	}

	void Driver::setTraceParsing(bool newTraceParsing)
	{
		traceParsing = newTraceParsing;
	}

	std::shared_ptr<ast::FunctionDefinition> Driver::getDefinedFunction(const std::string& name)
	{
		auto it = std::find_if(functionDefinitions.begin(), functionDefinitions.end(), [&](auto funcDef) { return (funcDef->getName() == name); });
		return (it==functionDefinitions.end() ? nullptr : *it);
	}

	std::shared_ptr<ast::VariableDefinition> Driver::getDefinedVariable(const std::string& name)
	{
		auto it = std::find_if(variableDefinitions.begin(), variableDefinitions.end(), [&](auto varDef) { return (varDef->getName() == name); });
		return (it==variableDefinitions.end() ? nullptr : *it);
	}

	bool Driver::isFunctionDefined(const std::string& name)
	{
		return (getDefinedFunction(name) != nullptr);
	}

	bool Driver::isVariableDefined(const std::string& name)
	{
		return (getDefinedVariable(name) != nullptr);
	}

	void Driver::throwIfDefined(const yy::location& loc, const std::string& name)
	{
		auto defFunc = getDefinedFunction(name);
		if(defFunc != nullptr)
			throw yy::ScratchCodeParser::syntax_error(loc, "identifier called '" + name + "' is already defined in this scope here: function at " + locationToString(nodeLocations[defFunc]));
	
		auto defVar = getDefinedVariable(name);
		if(defVar != nullptr)
			throw yy::ScratchCodeParser::syntax_error(loc, "identifier called '" + name + "' is already defined in this scope here: variable at " + locationToString(nodeLocations[defVar]));
	}
}
