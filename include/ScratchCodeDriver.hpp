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
#define YY_DECL yy::ScratchCodeParser::symbol_type yylex(ScratchCodeDriver& driver)



YY_DECL;
extern int yy_flex_debug;
extern FILE* yyin;

class ScratchCodeDriver
{
	private:
		int														result;
		std::string												filename;
		bool													traceLexing, traceParsing;

	public:
		std::shared_ptr<ast::StatementList>						syntaxTree;
		std::vector<std::shared_ptr<ast::FunctionDefinition>>	functionDefinitions;
		std::vector<std::shared_ptr<ast::VariableDefinition>>	variableDefinitions;
		std::unordered_map<std::shared_ptr<ast::Node>, yy::location> nodeLocations;									//needed for nodes where the location needs to be stored for later, currently used for FunctionDefinition, LoopControlStatement and VariableDefinition
	
		ScratchCodeDriver();
		ScratchCodeDriver(bool newTraceLexing, bool newTraceParsing);
		ScratchCodeDriver(std::shared_ptr<ast::StatementList> newSyntaxTree);
		ScratchCodeDriver(std::shared_ptr<ast::StatementList> newSyntaxTree, bool newTraceLexing, bool newTraceParsing);
		virtual ~ScratchCodeDriver();
		
		void													beginLexing();
		void													endLexing();
		int														parse(const std::string& newFilename);
		std::string												locationToString(const yy::location& loc);
		void													handleError(const yy::location& loc, const std::string& message);
		void													handleError(const std::string& message);
		const std::string&										getFilename();
		std::string*											getFilenamePointer();
		int														getResult();
		std::shared_ptr<ast::StatementList>						getSyntaxTree();
		void													setTraceLexing(bool newTraceLexing);
		void													setTraceParsing(bool newTraceParsing);
		std::shared_ptr<ast::FunctionDefinition>				getDefinedFunction(const std::string& name);
		std::shared_ptr<ast::VariableDefinition>				getDefinedVariable(const std::string& name);
		bool													isFunctionDefined(const std::string& name);
		bool													isVariableDefined(const std::string& name);
		void													throwIfDefined(const yy::ScratchCodeParser::location_type& loc, const std::string& name);
};
