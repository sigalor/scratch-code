#pragma once



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <string>
#include <map>

#include <ast/LexerTokenDefinitions.hpp>

#include "scratch-code.tab.hpp"
#define YY_DECL yy::ScratchCodeParser::symbol_type yylex(ScratchCodeDriver& driver)



YY_DECL;
extern int yy_flex_debug;
extern FILE* yyin;

class ScratchCodeDriver
{
	private:
		std::map<ast::Lexer::ParsedVariableType, std::string>	variables;
		int														result;
		std::string												filename;
		bool													traceLexing, traceParsing;

	public:
		ScratchCodeDriver();
		ScratchCodeDriver(bool newTraceLexing, bool newTraceParsing);
		virtual ~ScratchCodeDriver();
		
		void													beginLexing();
		void													endLexing();
		int														parse(const std::string& newFilename);
		void													handleError(const yy::location& loc, const std::string& message);
		void													handleError(const std::string& message);
		const std::map<ast::Lexer::ParsedVariableType, std::string>& getVariables();
		const std::string&										getFilename();
		std::string*											getFilenamePointer();
		int														getResult();
		void													setTraceLexing(bool newTraceLexing);
		void													setTraceParsing(bool newTraceParsing);
};
