#include "Main.hpp"



std::shared_ptr<ast::StatementList> syntaxTree = std::make_shared<ast::StatementList>(nullptr);



int main(int argc, char** argv)
{
	int					result = 0;
	std::string			outputFile("a.sb2");
	ScratchCodeDriver	driver(syntaxTree);
	
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
			std::cout << "compilation terminated due to parsing error " << driver.getResult() << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	
	std::cout << "result is " << result << std::endl;
	std::cout << "output file will be " << outputFile << std::endl;
	if(result == 0)
		std::cout << "\n" << ast::stringify(syntaxTree) << "\n";													//output the parsed abstract syntax tree
	
	return (result ? 1 : 0);
}
