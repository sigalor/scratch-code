/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/scratch-code.l
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



%{
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>
#include <boost/lexical_cast.hpp>

#include <ast/LexerTokenDefinitions.hpp>
#include <ast/RValueValue.hpp>

#include "scratch-code.tab.hpp"					//to get ScratchCodeParser class declaration
#include "ScratchCodeDriver.hpp"

static yy::location loc;
%}

%option noyywrap nounput batch debug noinput



%{
	//code run each time a pattern is matched
	#define YY_USER_ACTION loc.columns(yyleng);
%}

%%

%{
	//code run each time yylex is called
	loc.step();
%}



[ \t]+               { loc.step(); }
[\n]+                { loc.lines(yyleng); loc.step(); }
void                 { return yy::ScratchCodeParser::make_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Void, loc); }
bool                 { return yy::ScratchCodeParser::make_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Bool, loc); }
int                  { return yy::ScratchCodeParser::make_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Int, loc); }
real                 { return yy::ScratchCodeParser::make_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::Real, loc); }
string               { return yy::ScratchCodeParser::make_VARIABLE_TYPE(ast::Lexer::ParsedVariableType::String, loc); }
break                { return yy::ScratchCodeParser::make_LOOP_CONTROL_STATEMENT(ast::Lexer::ParsedLoopControlStatement::Break, loc); }
continue             { return yy::ScratchCodeParser::make_LOOP_CONTROL_STATEMENT(ast::Lexer::ParsedLoopControlStatement::Continue, loc); }
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

"+"                  { return yy::ScratchCodeParser::make_OP_PLUS(loc); }
"-"                  { return yy::ScratchCodeParser::make_OP_MINUS(loc); }
"++"                 { return yy::ScratchCodeParser::make_OP_INCREMENT(loc); }
"--"                 { return yy::ScratchCodeParser::make_OP_DECREMENT(loc); }
"!"                  { return yy::ScratchCodeParser::make_OP_LOGICAL_NOT(loc); }
"~"                  { return yy::ScratchCodeParser::make_OP_BITWISE_NOT(loc); }
"(bool)"             { return yy::ScratchCodeParser::make_OP_TYPECAST_BOOL(loc); }
"(int)"              { return yy::ScratchCodeParser::make_OP_TYPECAST_INT(loc); }
"(real)"             { return yy::ScratchCodeParser::make_OP_TYPECAST_REAL(loc); }
"(string)"           { return yy::ScratchCodeParser::make_OP_TYPECAST_STRING(loc); }

"*"                  { return yy::ScratchCodeParser::make_OP_MULTIPLY(loc); }
"/"                  { return yy::ScratchCodeParser::make_OP_DIVIDE(loc); }
"%"                  { return yy::ScratchCodeParser::make_OP_MODULO(loc); }
"&"                  { return yy::ScratchCodeParser::make_OP_BITWISE_AND(loc); }
"|"                  { return yy::ScratchCodeParser::make_OP_BITWISE_OR(loc); }
"^"                  { return yy::ScratchCodeParser::make_OP_BITWISE_XOR(loc); }
"<<"                 { return yy::ScratchCodeParser::make_OP_BITSHIFT_LEFT(loc); }
">>"                 { return yy::ScratchCodeParser::make_OP_BITSHIFT_RIGHT(loc); }
"&&"                 { return yy::ScratchCodeParser::make_OP_LOGICAL_AND(loc); }
"||"                 { return yy::ScratchCodeParser::make_OP_LOGICAL_OR(loc); }
"<"                  { return yy::ScratchCodeParser::make_OP_LESS_THAN(loc); }
"<="                 { return yy::ScratchCodeParser::make_OP_LESS_THAN_OR_EQUAL(loc); }
">"                  { return yy::ScratchCodeParser::make_OP_GREATER_THAN(loc); }
">="                 { return yy::ScratchCodeParser::make_OP_GREATER_THAN_OR_EQUAL(loc); }
"=="                 { return yy::ScratchCodeParser::make_OP_EQUAL(loc); }
"!="                 { return yy::ScratchCodeParser::make_OP_NOT_EQUAL(loc); }

"="                  { return yy::ScratchCodeParser::make_OP_ASSIGNMENT(loc); }
"+="                 { return yy::ScratchCodeParser::make_OP_ADD_ASSIGNMENT(loc); }
"-="                 { return yy::ScratchCodeParser::make_OP_SUBTRACT_ASSIGNMENT(loc); }
"*="                 { return yy::ScratchCodeParser::make_OP_MULTIPLY_ASSIGNMENT(loc); }
"/="                 { return yy::ScratchCodeParser::make_OP_DIVIDE_ASSIGNMENT(loc); }
"%="                 { return yy::ScratchCodeParser::make_OP_MODULO_ASSIGNMENT(loc); }
"&="                 { return yy::ScratchCodeParser::make_OP_BITWISE_AND_ASSIGNMENT(loc); }
"|="                 { return yy::ScratchCodeParser::make_OP_BITWISE_OR_ASSIGNMENT(loc); }
"^="                 { return yy::ScratchCodeParser::make_OP_BITWISE_XOR_ASSIGNMENT(loc); }
"<<="                { return yy::ScratchCodeParser::make_OP_BITSHIFT_LEFT_ASSIGNMENT(loc); }
">>="                { return yy::ScratchCodeParser::make_OP_BITSHIFT_RIGHT_ASSIGNMENT(loc); };

true|false           { std::string str(yytext, yyleng); return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, str=="true"), loc); }
[1-9][0-9]*          { std::string str(yytext, yyleng); uint64_t val; try { val = boost::lexical_cast<uint64_t>(str); } catch(const boost::bad_lexical_cast& ex) { throw yy::ScratchCodeParser::syntax_error(loc, "invalid integer value: " + str + ": " + ex.what()); } return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, val), loc); }		//there are no [+-]? at the beginning, as + and - become UnaryOperations
(([1-9][0-9]*\.?[0-9]*)|(\.[0-9]+))([Ee][+-]?[0-9]+)? { std::string str(yytext, yyleng); double val; try { val = boost::lexical_cast<double>(str); } catch(const boost::bad_lexical_cast& ex) { throw yy::ScratchCodeParser::syntax_error(loc, "invalid floating point value: " + str + ": " + ex.what()); } return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, val), loc); }		//regex from http://stackoverflow.com/a/2293793
\".*\"               { std::string str(yytext+1, yyleng-2); return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, str), loc); }
[a-zA-Z][0-9a-zA-Z]* { return yy::ScratchCodeParser::make_IDENTIFIER(yytext, loc); }
.                    { throw yy::ScratchCodeParser::syntax_error(loc, "invalid character: '" + std::string(yytext, yyleng) + "'"); }		//from http://stackoverflow.com/a/18888761
<<EOF>>              { return yy::ScratchCodeParser::make_END(loc); }
%%
