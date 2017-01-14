/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/OpcodeAliases.cpp
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



#include "OpcodeAliases.hpp"



namespace op = sc::ObjectParams;

namespace sc
{
	namespace OpcodeAliases
	{
		const std::function<void(Object*)> isStageCondition([](Object* obj)
		{
			if(obj->getType() != op::Type::Stage)
				throw GeneralException("object needs to be of type '" + op::typeToReadableString(op::Type::Stage) + "'");
		});
		
		const std::function<void(Object*)> isGenericCondition([](Object* obj)
		{
			if(obj->getType() != op::Type::Generic)
				throw GeneralException("object needs to be of type '" + op::typeToReadableString(op::Type::Generic) + "'");
		});
		
		const std::vector<OpcodeAlias> opcodeAliases =
		{
			OpcodeAlias(isGenericCondition,	"say:",							constructOpcodeAlias("scratch_say",			{ ast::Lexer::ParsedVariableType::String })),
			OpcodeAlias(nullptr,			"say:duration:elapsed:from:",	constructOpcodeAlias("scratch_sayDuration",	{ ast::Lexer::ParsedVariableType::String, ast::Lexer::ParsedVariableType::Real }))
		};
		
		const std::vector<FunctionModifier> functionModifiers =
		{
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnGreenFlag,
				nullptr,
				OpcodeAlias(nullptr, "whenGreenFlag", constructOpcodeAlias("scratch_onGreenFlag", {}))
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnKeyPressed,
				[](Object* targetObject, std::shared_ptr<ast::ValueList> modifierArgs)
				{
					std::string keyStr(boost::get<std::string>(std::static_pointer_cast<ast::RValueValue>(modifierArgs->getValues()[0])->getValue()));
					if(keyStr == "any"  ||  keyStr == "space"  ||  keyStr == "up arrow"  ||  keyStr == "down arrow"  ||  keyStr == "right arrow"  ||  keyStr == "left arrow")
						return;
					if(keyStr.size() == 1  &&  ((keyStr[0] >= 'a'  &&  keyStr[0] <= 'z')  ||  (keyStr[0] >= '0'  &&  keyStr[0] <= '9')))
						return;
					throw GeneralException("invalid key: '" + keyStr + "'");
				},
				OpcodeAlias(nullptr, "whenKeyPressed", constructOpcodeAlias("scratch_onKeyPressed", { ast::Lexer::ParsedVariableType::String }))
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnThisClicked,
				nullptr,
				OpcodeAlias(nullptr, "whenClicked", constructOpcodeAlias("scratch_onThisClicked", {}))
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnBackdropSwitch,
				[](Object* targetObject, std::shared_ptr<ast::ValueList> modifierArgs)
				{
					std::string sensorStr(boost::get<std::string>(std::static_pointer_cast<ast::RValueValue>(modifierArgs->getValues()[1])->getValue()));
					if(sensorStr != "loudness"  &&  sensorStr != "timer"  &&  sensorStr != "video motion")
						throw GeneralException("invalid sensor: '" + sensorStr + "'");
				},
				OpcodeAlias(nullptr, "whenSceneStarts", constructOpcodeAlias("scratch_onBackdropSwitch", { ast::Lexer::ParsedVariableType::String }))
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnSensorGreaterThan,
				[](Object* targetObject, std::shared_ptr<ast::ValueList> modifierArgs)
				{
					std::string sensorStr(boost::get<std::string>(std::static_pointer_cast<ast::RValueValue>(modifierArgs->getValues()[1])->getValue()));
					if(sensorStr != "loudness"  &&  sensorStr != "timer"  &&  sensorStr != "video motion")
						throw GeneralException("invalid sensor: '" + sensorStr + "'");
				},
				OpcodeAlias(nullptr, "whenSensorGreaterThan", constructOpcodeAlias("scratch_onSensorGreaterThan", { ast::Lexer::ParsedVariableType::String, ast::Lexer::ParsedVariableType::Int }))
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnReceive,
				nullptr,
				OpcodeAlias(nullptr, "whenIReceive", constructOpcodeAlias("scratch_onReceive", { ast::Lexer::ParsedVariableType::String }))
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnClone,
				nullptr,
				OpcodeAlias(isGenericCondition, "whenCloned", constructOpcodeAlias("scratch_onClone", {}))
			)
		};
		
		const std::vector<std::shared_ptr<ast::FunctionDefinition>> nativeFunctionDefinitions([&]()
		{
			std::vector<std::shared_ptr<ast::FunctionDefinition>> ret;
			for(auto& x : opcodeAliases)
				ret.push_back(x.aliasFuncDef);
			for(auto& x : functionModifiers)
				ret.push_back(x.opcodeAlias.aliasFuncDef);
			return ret;
		}());
		
		
		
		
		
		std::shared_ptr<ast::VariableDefinitionList> constructOpcodeArgs(std::shared_ptr<ast::Node> parent, const std::vector<ast::Lexer::ParsedVariableType>& argTypes)
		{
			std::shared_ptr<ast::VariableDefinitionList> ret = std::make_shared<ast::VariableDefinitionList>(parent);
			std::size_t argTypeCounter = 0;
			
			for(auto& t : argTypes)
			{
				ret->addVarDef(std::make_shared<ast::VariableDefinition>(ret, t, "arg" + std::to_string(argTypeCounter)));
				++argTypeCounter;
			}
			
			return ret;
		}
		
		std::shared_ptr<ast::FunctionDefinition> constructOpcodeAlias(const std::string& alias, const std::vector<ast::Lexer::ParsedVariableType>& argTypes)
		{
			Utilities::validateIdentifier("opcode alias", alias);
			std::shared_ptr<ast::FunctionDefinition> ret = std::make_shared<ast::FunctionDefinition>(nullptr, ast::Lexer::ParsedVariableType::Void, alias, nullptr, ast::Lexer::ParsedFunctionModifier::Invalid, nullptr, nullptr);
			
			ret->setArgs(constructOpcodeArgs(ret, argTypes));
			ret->setBody(std::make_shared<ast::StatementList>(ret));
			
			return ret;
		}
		
		decltype(opcodeAliases)::const_iterator getIteratorFromAlias(const std::string& alias)
		{
			return std::find_if(opcodeAliases.begin(), opcodeAliases.end(), [&](auto& x) { return (x.aliasFuncDef->getName() == alias); });
		}
		
		bool hasAlias(const std::string& alias)
		{
			return (getIteratorFromAlias(alias) != opcodeAliases.end());
		}
		
		const std::string& getOpcodeFromAlias(const std::string& alias)
		{
			auto it = getIteratorFromAlias(alias);
			if(it == opcodeAliases.end())
				throw GeneralException("alias '" + alias + "' does not exist, thus no opcode is assigned to it either");
			return it->opcode;
		}
	}
}
