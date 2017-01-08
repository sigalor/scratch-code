/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Translator.cpp
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



#include "Translator.hpp"



namespace sc
{
	void Translator::translateStatement(std::shared_ptr<ast::Statement> input, rapidjson::Value& valDest)
	{
		if(input->isA<ast::FunctionDefinition>())
			translateFunctionDefinition(std::static_pointer_cast<ast::FunctionDefinition>(input), valDest);
		else if(input->isABase<ast::Value>())
			translateValue(std::static_pointer_cast<ast::Value>(input), valDest);
		else if(input->isABase<ast::ControlFlowStatement>())
			translateControlFlowStatement(std::static_pointer_cast<ast::ControlFlowStatement>(input), valDest);
	}
	
	void Translator::translateFunctionDefinition(std::shared_ptr<ast::FunctionDefinition> input, rapidjson::Value& valDest)
	{
		using namespace rapidjson;
		
		Value head(kArrayType), argNames(kArrayType), argDefaultValues(kArrayType), bodyContents(kArrayType);
		std::string signature(input->getName() + "( ");
		std::size_t argCounter = 0;
		
		for(auto arg : input->getArgs()->getVarDefs())
		{
			signature += (argCounter==0 ? "" : " , ");
			switch(arg->getType())
			{
				case ast::Lexer::ParsedVariableType::Bool:
				{
					signature += "%b";
					argDefaultValues.PushBack(false, alloc);
					break;
				}
				case ast::Lexer::ParsedVariableType::Int:
				case ast::Lexer::ParsedVariableType::Real:
				{
					signature += "%n";
					argDefaultValues.PushBack(1, alloc);
					break;
				}
				case ast::Lexer::ParsedVariableType::String:
				{
					signature += "%s";
					argDefaultValues.PushBack("", alloc);
					break;
				}
				default: break;
			}
			argNames.PushBack(Value(arg->getName().c_str(), alloc), alloc);
			++argCounter;
		}
		signature += " )";
		
		valDest.SetArray();
		head.PushBack("procDef", alloc);
		head.PushBack(Value(signature.c_str(), alloc), alloc);
		head.PushBack(argNames, alloc);
		head.PushBack(argDefaultValues, alloc);
		head.PushBack(false, alloc);
		valDest.PushBack(head, alloc);
		translateStatementList(input->getBody(), valDest, true);
	}
	
	void Translator::translateValue(std::shared_ptr<ast::Value> input, rapidjson::Value& valDest)
	{
		if(input->isABase<ast::RValue>())
			translateRValue(std::static_pointer_cast<ast::RValue>(input), valDest);
	}
	
	void Translator::translateRValue(std::shared_ptr<ast::RValue> input, rapidjson::Value& valDest)
	{
		if(input->isA<ast::RValueValue>())
			translateRValueValue(std::static_pointer_cast<ast::RValueValue>(input), valDest);
		else if(input->isA<ast::FunctionCall>())
			translateFunctionCall(std::static_pointer_cast<ast::FunctionCall>(input), valDest);
	}
	
	void Translator::translateRValueValue(std::shared_ptr<ast::RValueValue> input, rapidjson::Value& valDest)
	{
		ast::RValueValue::ValueVariantType& value = input->getValue();
		switch(input->getType())
		{
			case ast::Lexer::ParsedVariableType::Bool	: valDest.SetBool(boost::get<bool>(value)); break;
			case ast::Lexer::ParsedVariableType::Int	: valDest.SetUint64(boost::get<uint64_t>(value)); break;		//note that an RValueValue can ONLY hold positive types! Negative values are only possible in combination with ParsedUnaryOperation::UnaryMinus!
			case ast::Lexer::ParsedVariableType::Real	: valDest.SetDouble(boost::get<double>(value)); break;
			case ast::Lexer::ParsedVariableType::String	: valDest.SetString(boost::get<std::string>(value).c_str(), alloc); break;
			default										: break;
		}
	}
	
	void Translator::translateFunctionCall(std::shared_ptr<ast::FunctionCall> input, rapidjson::Value& valDest)
	{
		using namespace rapidjson;
		
		auto opcodeIter = OpcodeAliases::getIteratorFromAlias(input->getAssocFunc()->getName());
		
		valDest.SetArray();
		if(opcodeIter != OpcodeAliases::opcodeAliases.end())
		{
			Value argBuffer;
			
			//of course only call the condition when it's set at all; when it is, use try-catch, because it can throw exceptions (e.g. when a "say" block is used in a stage object)
			if(opcodeIter->condition)
			{
				try
					{ opcodeIter->condition(targetObject); }
				catch(const GeneralException& e)
					{ throw GeneralException(parsingDriver->locationToString(parsingDriver->nodeLocations[input]) + ": object '" + targetObject->getName() + "' is not qualified for the use of the function '" + input->getAssocFunc()->getName() + "': " + e.what()); }
			}
			
			//translate all arguments
			valDest.PushBack(Value(opcodeIter->opcode.c_str(), alloc), alloc);
			for(auto v : input->getArgs()->getValues())
			{
				translateValue(v, argBuffer);
				valDest.PushBack(argBuffer, alloc);
			}
		}
		else
		{
			//TODO (custom function calls)
		}
	}
	
	void Translator::translateControlFlowStatement(std::shared_ptr<ast::ControlFlowStatement> input, rapidjson::Value& valDest)
	{
		if(input->isA<ast::Conditional>())
			translateConditional(std::static_pointer_cast<ast::Conditional>(input), valDest);
	}
	
	void Translator::translateConditional(std::shared_ptr<ast::Conditional> input, rapidjson::Value& valDest)
	{
		using namespace rapidjson;
		
		Value translatedCondition, translatedBody;
		
		valDest.SetArray();
		valDest.PushBack(Value(input->getAlternativeBody()==nullptr ? "doIf" : "doIfElse", alloc), alloc);
		translateValue(input->getCondition(), translatedCondition);
		valDest.PushBack(translatedCondition, alloc);
		for(auto body : { input->getConsequenceBody(), input->getAlternativeBody() })
		{
			if(body != nullptr)																					//only alternative body can become a nullptr
			{
				translateStatementList(body, translatedBody);
				if(translatedBody.Size() == 0)
					valDest.PushBack(Value(kNullType), alloc);
				else
					valDest.PushBack(translatedBody, alloc);
			}
		}
	}
	
	void Translator::translateStatementList(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, bool append)
	{
		using namespace rapidjson;
		
		Value translatedStatement;
		
		if(!append)
			valDest.SetArray();
		for(auto stmt : input->getStatements())
		{
			translateStatement(stmt, translatedStatement);
			valDest.PushBack(translatedStatement, alloc);
		}
	}
	
	Translator::Translator(Object* newTargetObject, std::shared_ptr<Driver> newParsingDriver, rapidjson::Document::AllocatorType& newAlloc) : targetObject(newTargetObject), parsingDriver(newParsingDriver), alloc(newAlloc)
	{
		//empty
	}

	void Translator::translate(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest)
	{
		using namespace rapidjson;
		
		Value translatedStatementBuffer, blockBuffer;
		int xCoord = 10, yCoord = 10;
		
		valDest.SetArray();
		for(auto stmt : input->getStatements())
		{
			if(stmt->isA<ast::FunctionDefinition>())
			{
				translateStatement(stmt, translatedStatementBuffer);
				blockBuffer.SetArray();
				blockBuffer.PushBack(xCoord, alloc);
				blockBuffer.PushBack(yCoord, alloc);
				blockBuffer.PushBack(translatedStatementBuffer, alloc);
				valDest.PushBack(blockBuffer, alloc);
				yCoord += 20;
			}
		}
	}
}
