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
	namespace Translator
	{
		/*BlockTuple::BlockTuple()
		{
			//empty
		}
		
		BlockTuple::BlockTuple(const std::string& newOpcode) : opcode(newOpcode)
		{
			//empty
		}
		
		rapidjson::Value& addArgument()
		{
			arguments.push_back(rapidjson::Value());
			return arguments.back();
		}*/
		
		void translateStatement(std::shared_ptr<ast::Statement> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
		{
			if(input->isA<ast::FunctionDefinition>())
				translateFunctionDefinition(std::static_pointer_cast<ast::FunctionDefinition>(input), valDest, alloc);
			else if(input->isABase<ast::ControlFlowStatement>())
				translateControlFlowStatement(std::static_pointer_cast<ast::ControlFlowStatement>(input), valDest, alloc);
		}
		
		void translateFunctionDefinition(std::shared_ptr<ast::FunctionDefinition> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
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
			translateStatementList(input->getBody(), valDest, alloc, true);
		}
		
		void translateValue(std::shared_ptr<ast::Value> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
		{
			//if(input->isA<ast::Conditional>())
			//	translateConditional(std::static_pointer_cast<ast::Conditional>(input), valDest, alloc);
			valDest.SetBool(false);
		}
		
		void translateControlFlowStatement(std::shared_ptr<ast::ControlFlowStatement> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
		{
			if(input->isA<ast::Conditional>())
				translateConditional(std::static_pointer_cast<ast::Conditional>(input), valDest, alloc);
		}
		
		void translateConditional(std::shared_ptr<ast::Conditional> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
		{
			using namespace rapidjson;
			
			Value translatedCondition, translatedBody;
			
			valDest.SetArray();
			valDest.PushBack(Value(input->getAlternativeBody()==nullptr ? "doIf" : "doIfElse", alloc), alloc);
			translateValue(input->getCondition(), translatedCondition, alloc);
			valDest.PushBack(translatedCondition, alloc);
			for(auto body : { input->getConsequenceBody(), input->getAlternativeBody() })
			{
				if(body != nullptr)																					//only alternative body can become a nullptr
				{
					translateStatementList(body, translatedBody, alloc);
					if(translatedBody.Size() == 0)
						valDest.PushBack(Value(kNullType), alloc);
					else
						valDest.PushBack(translatedBody, alloc);
				}
			}
		}
		
		void translateStatementList(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc, bool append)
		{
			using namespace rapidjson;
			
			Value translatedStatement;
			
			if(!append)
				valDest.SetArray();
			for(auto stmt : input->getStatements())
			{
				translateStatement(stmt, translatedStatement, alloc);
				valDest.PushBack(translatedStatement, alloc);
			}
		}
	
		void translate(std::shared_ptr<ast::StatementList> input, rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc)
		{
			using namespace rapidjson;
			
			Value translatedStatementBuffer, blockBuffer;
			int xCoord = 10, yCoord = 10;
			
			valDest.SetArray();
			for(auto stmt : input->getStatements())
			{
				if(stmt->isA<ast::FunctionDefinition>())
				{
					translateStatement(stmt, translatedStatementBuffer, alloc);
					blockBuffer.SetArray();
					blockBuffer.PushBack(xCoord, alloc);
					blockBuffer.PushBack(yCoord, alloc);
					blockBuffer.PushBack(translatedStatementBuffer, alloc);
					valDest.PushBack(blockBuffer, alloc);
					yCoord += 20;
				}
			}
			
			/*Value command(kArrayType), commandContents(kArrayType), commandContentsName(kArrayType), commandContentsAction(kArrayType);
			valDest.SetArray();
			commandContentsName.PushBack("whenGreenFlag", alloc);
			commandContentsAction.PushBack("wait:elapsed:from:", alloc);
			commandContentsAction.PushBack(1, alloc);
			commandContents.PushBack(commandContentsName, alloc);
			commandContents.PushBack(commandContentsAction, alloc);
			command.PushBack(14, alloc);
			command.PushBack(14, alloc);
			command.PushBack(commandContents, alloc);
			valDest.PushBack(command, alloc);*/
		}
	}
}
