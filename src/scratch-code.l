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
void                 { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Void, loc); }
bool                 { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Bool, loc); }
int                  { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Int, loc); }
real                 { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Real, loc); }
string               { return yy::ScratchCodeParser::make_PARSED_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::String, loc); }
if                   { return yy::ScratchCodeParser::make_IF(loc); }
else                 { return yy::ScratchCodeParser::make_ELSE(loc); }
while                { return yy::ScratchCodeParser::make_WHILE(loc); }
for                  { return yy::ScratchCodeParser::make_FOR(loc); }
return               { return yy::ScratchCodeParser::make_RETURN(loc); }
"("                  { return yy::ScratchCodeParser::make_ROUND_BRACKET_OPEN(loc); }
")"                  { return yy::ScratchCodeParser::make_ROUND_BRACKET_CLOSED(loc); }
"["                  { return yy::ScratchCodeParser::make_SQUARE_BRACKET_OPEN(loc); }
"]"                  { return yy::ScratchCodeParser::make_SQUARE_BRACKET_CLOSED(loc); }
"{"                  { return yy::ScratchCodeParser::make_CURLY_BRACKET_OPEN(loc); }
"}"                  { return yy::ScratchCodeParser::make_CURLY_BRACKET_CLOSED(loc); }
","                  { return yy::ScratchCodeParser::make_COMMA(loc); }
";"                  { return yy::ScratchCodeParser::make_SEMICOLON(loc); }
[a-zA-Z][0-9a-zA-Z]* { return yy::ScratchCodeParser::make_IDENTIFIER(yytext, loc); }
.                    { driver.handleError(loc, "invalid character"); }
<<EOF>>              { return yy::ScratchCodeParser::make_END(loc); }
%%
