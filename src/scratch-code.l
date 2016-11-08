%{
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>

#include <ast/LexerTokenDefinitions.hpp>

#include "scratch-code.tab.hpp"					//to get ScratchCodeParser class definition
#include "ScratchCodeDriver.hpp"

static yy::location loc;
%}

%option noyywrap nounput batch debug noinput



%{
	//code run each time a pattern in matched
	#define YY_USER_ACTION loc.columns(yyleng);
%}

%%

%{
	//code run each time yylex is called
	loc.step();
%}



[ \t]+               { loc.step(); }
[\n]+                { loc.lines(yyleng); loc.step(); }
int                  { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Int, loc); }
float                { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Float, loc); }
[a-zA-Z][0-9a-zA-Z]* { return yy::ScratchCodeParser::make_IDENTIFIER(yytext, loc); }
.                    { driver.handleError(loc, "invalid character"); }
<<EOF>>              { return yy::ScratchCodeParser::symbol_type(); }
%%
