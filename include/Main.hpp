#pragma once



#include <cstdlib>
#include <iostream>
#include <string>

#include <ast/AST.hpp>

#include "ScratchCodeDriver.hpp"



extern std::shared_ptr<ast::StatementList>						syntaxTree;

int																main(int argc, char** argv);
