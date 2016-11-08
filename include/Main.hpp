#pragma once



#include <iostream>
#include <string>

#include <ast/AST.hpp>

#include "ScratchCodeDriver.hpp"



//stuff for flex and bison
/*extern "C" int									yylex();
extern "C" int									yyparse();
extern FILE*									yyin;
void											yyerror(const char* s);*/												//function for flex error reporting



extern std::shared_ptr<ast::StatementList>						parsedStatements;

int																main(int argc, char** argv);
