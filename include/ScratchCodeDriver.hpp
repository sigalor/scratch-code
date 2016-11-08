#pragma once



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <string>
#include <map>
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
		std::shared_ptr<ast::StatementList>						parsedStatementList;

	public:
		std::shared_ptr<ast::StatementList>						parentStatementList;
	
		ScratchCodeDriver();
		ScratchCodeDriver(bool newTraceLexing, bool newTraceParsing);
		ScratchCodeDriver(std::shared_ptr<ast::StatementList> newParsedStatementList);
		ScratchCodeDriver(std::shared_ptr<ast::StatementList> newParsedStatementList, bool newTraceLexing, bool newTraceParsing);
		virtual ~ScratchCodeDriver();
		
		void													beginLexing();
		void													endLexing();
		int														parse(const std::string& newFilename);
		void													handleError(const yy::location& loc, const std::string& message);
		void													handleError(const std::string& message);
		const std::string&										getFilename();
		std::string*											getFilenamePointer();
		int														getResult();
		std::shared_ptr<ast::StatementList>						getParsedStatementList();
		void													setTraceLexing(bool newTraceLexing);
		void													setTraceParsing(bool newTraceParsing);
};
