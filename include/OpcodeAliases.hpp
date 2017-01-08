/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/OpcodeAliases.hpp
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



#pragma once



#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <functional>
#include <ast/AST.hpp>

#include "Object.hpp"
#include "ObjectParams.hpp"
#include "GeneralException.hpp"
#include "Utilities.hpp"



namespace sc
{
	class Object;

	namespace OpcodeAliases
	{
		class OpcodeAlias
		{
			public:
				std::function<void(Object*)>					condition;
				std::string										opcode;
				std::shared_ptr<ast::FunctionDefinition>		aliasFuncDef;
				
				OpcodeAlias(const std::function<void(Object*)>& newCondition, const std::string& newOpcode, std::shared_ptr<ast::FunctionDefinition> newAliasFuncDef) : condition(newCondition), opcode(newOpcode), aliasFuncDef(newAliasFuncDef)
				{
					//empty
				}
		};
		
		extern const std::function<void(Object*)>				isStageCondition, isGenericCondition;				//in contrast to ObjectParams::isStageCondition, this one THROWS a sc::GeneralException with a message instead of returning 'bool'. THIS is what OpcodeAlias::condition expects. It has NOTHING to do with the condition needed by 'ManifestDefinitions'/'ManifestEntry'.
		extern const std::vector<OpcodeAlias>					opcodeAliases;
		extern const std::vector<std::shared_ptr<ast::FunctionDefinition>> aliasFunctionDefinitions;
		
		std::shared_ptr<ast::VariableDefinitionList>			constructOpcodeArgs(std::shared_ptr<ast::Node> parent, const std::vector<ast::Lexer::ParsedVariableType>& argTypes);
		std::shared_ptr<ast::FunctionDefinition>				constructOpcodeAlias(const std::string& alias, const std::vector<ast::Lexer::ParsedVariableType>& argTypes);
		decltype(opcodeAliases)::const_iterator					getIteratorFromAlias(const std::string& alias);
		bool													hasAlias(const std::string& alias);
		const std::string&										getOpcodeFromAlias(Object* targetObject, const std::string& alias);
	};
}
