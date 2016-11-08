#include "Main.hpp"



std::shared_ptr<ast::StatementList> parsedStatements(std::make_shared<ast::StatementList>());



int main(int argc, char** argv)
{
	int result = 0;
	ScratchCodeDriver driver(parsedStatements);
	
	for(int i=1; i<argc; ++i)
	{
		if(argv[i] == std::string("-l"))
			driver.setTraceLexing(true);
		else if(argv[i] == std::string("-p"))
			driver.setTraceParsing(true);
		else if(driver.parse(argv[i]) == 0)
			std::cout << "Final parser result code: " << driver.getResult() << std::endl;
		else
			result = 1;
	}
	
	std::cout << "\n" << ast::stringify(parsedStatements) << "\n";													//output the parsed abstract syntax tree
	return result;
}
