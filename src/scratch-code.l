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
"="                  { return yy::ScratchCodeParser::make_BINOP_ASSIGNMENT(loc); }
true|false           { std::string str(yytext, yyleng); return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, str=="true"), loc); }
[+-]?[1-9][0-9]*     { std::string str(yytext, yyleng); uint64_t val; try { val = boost::lexical_cast<uint64_t>(str); } catch(const boost::bad_lexical_cast& ex) { throw yy::ScratchCodeParser::syntax_error(loc, "invalid integer value: " + str + ": " + ex.what()); } return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, val), loc); }
[+-]?(([1-9][0-9]*\.?[0-9]*)|(\.[0-9]+))([Ee][+-]?[0-9]+)? { std::string str(yytext, yyleng); double val; try { val = boost::lexical_cast<double>(str); } catch(const boost::bad_lexical_cast& ex) { throw yy::ScratchCodeParser::syntax_error(loc, "invalid floating point value: " + str + ": " + ex.what()); } return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, val), loc); }		//regex from http://stackoverflow.com/a/2293793
\".*\"               { std::string str(yytext+1, yyleng-2); return yy::ScratchCodeParser::make_RVALUE_VALUE(std::make_shared<ast::RValueValue>(nullptr, str), loc); }
[a-zA-Z][0-9a-zA-Z]* { return yy::ScratchCodeParser::make_IDENTIFIER(yytext, loc); }
.                    { throw yy::ScratchCodeParser::syntax_error(loc, "invalid character: '" + std::string(yytext, yyleng) + "'"); }		//from http://stackoverflow.com/a/18888761
<<EOF>>              { return yy::ScratchCodeParser::make_END(loc); }
%%
