/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/ScratchCodeDriver.cpp
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



#include "ScratchCodeDriver.hpp"



ScratchCodeDriver::ScratchCodeDriver() : result(0), traceLexing(false), traceParsing(false) { }
ScratchCodeDriver::ScratchCodeDriver(bool newTraceLexing, bool newTraceParsing) : result(0), traceLexing(newTraceLexing), traceParsing(newTraceParsing) { }
ScratchCodeDriver::ScratchCodeDriver(std::shared_ptr<ast::StatementList> newSyntaxTree) : result(0), traceLexing(false), traceParsing(false), syntaxTree(newSyntaxTree) { }
ScratchCodeDriver::ScratchCodeDriver(std::shared_ptr<ast::StatementList> newSyntaxTree, bool newTraceLexing, bool newTraceParsing) : result(0), traceLexing(newTraceLexing), traceParsing(newTraceParsing), syntaxTree(newSyntaxTree) { }
ScratchCodeDriver::~ScratchCodeDriver() { }

void ScratchCodeDriver::beginLexing()
{
	yy_flex_debug = traceLexing;
	if(filename.empty()  ||  filename == "-")
		yyin = stdin;
	else if(!(yyin = fopen(filename.c_str(), "r")))
	{
		handleError("cannot open " + filename + ": " + strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void ScratchCodeDriver::endLexing()
{
	fclose(yyin);
}

int ScratchCodeDriver::parse(const std::string& newFilename)
{
	yy::ScratchCodeParser parser(*this);

	filename = newFilename;
	beginLexing();
	parser.set_debug_level(traceParsing);
	result = parser.parse();
	endLexing();
	
	return result;
}

std::string ScratchCodeDriver::locationToString(const yy::location& loc)
{
	return filename + ":" + std::to_string(loc.begin.line) + ":" + std::to_string(loc.begin.column);
}

void ScratchCodeDriver::handleError(const yy::location& loc, const std::string& message)
{
	std::cerr << locationToString(loc) << ": " << message << std::endl;
}

void ScratchCodeDriver::handleError(const std::string& message)
{
	std::cerr << message << std::endl;
}

const std::string& ScratchCodeDriver::getFilename()
{
	return filename;
}

std::string* ScratchCodeDriver::getFilenamePointer()
{
	return &filename;
}

int ScratchCodeDriver::getResult()
{
	return result;
}

std::shared_ptr<ast::StatementList> ScratchCodeDriver::getSyntaxTree()
{
	return syntaxTree;
}

void ScratchCodeDriver::setTraceLexing(bool newTraceLexing)
{
	traceLexing = newTraceLexing;
}

void ScratchCodeDriver::setTraceParsing(bool newTraceParsing)
{
	traceParsing = newTraceParsing;
}

std::shared_ptr<ast::FunctionDefinition> ScratchCodeDriver::getDefinedFunction(const std::string& name)
{
	auto it = std::find_if(functionDefinitions.begin(), functionDefinitions.end(), [&](auto funcDef) { return (funcDef->getName() == name); });
	return (it==functionDefinitions.end() ? nullptr : *it);
}

std::shared_ptr<ast::VariableDefinition> ScratchCodeDriver::getDefinedVariable(const std::string& name)
{
	auto it = std::find_if(variableDefinitions.begin(), variableDefinitions.end(), [&](auto varDef) { return (varDef->getName() == name); });
	return (it==variableDefinitions.end() ? nullptr : *it);
}

bool ScratchCodeDriver::isFunctionDefined(const std::string& name)
{
	return (getDefinedFunction(name) != nullptr);
}

bool ScratchCodeDriver::isVariableDefined(const std::string& name)
{
	return (getDefinedVariable(name) != nullptr);
}

void ScratchCodeDriver::throwIfDefined(const yy::location& loc, const std::string& name)
{
	auto defFunc = getDefinedFunction(name);
	if(defFunc != nullptr)
		throw yy::ScratchCodeParser::syntax_error(loc, "identifier called '" + name + "' is already defined in this scope here: function at " + locationToString(nodeLocations[defFunc]));
	
	auto defVar = getDefinedVariable(name);
	if(defVar != nullptr)
		throw yy::ScratchCodeParser::syntax_error(loc, "identifier called '" + name + "' is already defined in this scope here: variable at " + locationToString(nodeLocations[defVar]));
}

