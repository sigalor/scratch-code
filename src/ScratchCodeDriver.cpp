#include "ScratchCodeDriver.hpp"



ScratchCodeDriver::ScratchCodeDriver() : result(0), traceLexing(false), traceParsing(false) { }
ScratchCodeDriver::ScratchCodeDriver(bool newTraceLexing, bool newTraceParsing) : result(0), traceLexing(newTraceLexing), traceParsing(newTraceParsing) { }
ScratchCodeDriver::ScratchCodeDriver(std::shared_ptr<ast::StatementList> newParsedStatementList) : result(0), traceLexing(false), traceParsing(false), parsedStatementList(newParsedStatementList) { }
ScratchCodeDriver::ScratchCodeDriver(std::shared_ptr<ast::StatementList> newParsedStatementList, bool newTraceLexing, bool newTraceParsing) : result(0), traceLexing(newTraceLexing), traceParsing(newTraceParsing), parsedStatementList(newParsedStatementList) { }
ScratchCodeDriver::~ScratchCodeDriver() { }

void ScratchCodeDriver::beginLexing()
{
	yy_flex_debug = traceLexing;
	if(filename.empty()  ||  filename == "-")
		yyin = stdin;
	else if(!(yyin = fopen(filename.c_str(), "r")))
	{
		handleError("cannot open " + filename + ": " + strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void ScratchCodeDriver::endLexing()
{
	fclose(yyin);
}

int ScratchCodeDriver::parse(const std::string& newFilename)
{
	yy::ScratchCodeParser parser(*this);

	filename = newFilename;
	parentStatementList = parsedStatementList;
	beginLexing();
	parser.set_debug_level(traceParsing);
	result = parser.parse();
	endLexing();
	
	return result;
}

void ScratchCodeDriver::handleError(const yy::location& loc, const std::string& message)
{
	std::cerr << (loc.begin.filename==nullptr ? "<unknown>" : *loc.begin.filename) << ":" << loc.begin.line << ":" << loc.begin.column << ": " << message << std::endl;
}

void ScratchCodeDriver::handleError(const std::string& message)
{
	std::cerr << message << std::endl;
}

const std::string& ScratchCodeDriver::getFilename()
{
	return filename;
}

std::string* ScratchCodeDriver::getFilenamePointer()
{
	return &filename;
}

int ScratchCodeDriver::getResult()
{
	return result;
}

std::shared_ptr<ast::StatementList> ScratchCodeDriver::getParsedStatementList()
{
	return parsedStatementList;
}

void ScratchCodeDriver::setTraceLexing(bool newTraceLexing)
{
	traceLexing = newTraceLexing;
}

void ScratchCodeDriver::setTraceParsing(bool newTraceParsing)
{
	traceParsing = newTraceParsing;
}
