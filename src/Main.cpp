/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Main.cpp
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



#include "Main.hpp"



int main(int argc, char** argv)
{
	int									result = 0;
	std::string							outputFile("a.sb2");
	std::shared_ptr<ast::StatementList>	syntaxTree = std::make_shared<ast::StatementList>(nullptr);
	ScratchCodeDriver					driver(syntaxTree);
	
	for(int i=1; i<argc; ++i)
	{
		if(argv[i] == std::string("-l"))
			driver.setTraceLexing(true);
		else if(argv[i] == std::string("-p"))
			driver.setTraceParsing(true);
		else if(argv[i] == std::string("-o"))
			outputFile.clear();
		else if(outputFile.empty())
			outputFile = argv[i];
		else if((result = driver.parse(argv[i])) != 0)
		{
			std::cerr << "compilation terminated due to parsing error " << driver.getResult() << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	
	if(result == 0)
		std::cout << "\n" << ast::stringify(syntaxTree) << "\n";													//output the parsed abstract syntax tree
	ScratchCodeTranslator::translate(syntaxTree, outputFile);
	
	return (result ? 1 : 0);
}
