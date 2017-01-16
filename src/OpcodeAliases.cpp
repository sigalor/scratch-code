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
		
		
		
		
		
		OpcodeAliasArgument::OpcodeAliasArgument(ast::Lexer::ParsedVariableType newType) : type(newType) { }
		OpcodeAliasArgument::OpcodeAliasArgument(ast::Lexer::ParsedVariableType newType, const ArgumentValidator& newValidator) : type(newType), validator(newValidator) { }
		
		OpcodeAlias::OpcodeAlias(const std::function<void(Object*)>& newCondition, const std::string& newOpcode, const std::string& newAlias, const std::vector<OpcodeAliasArgument>& arguments) : condition(newCondition), opcode(newOpcode)
		{
			std::vector<ast::Lexer::ParsedVariableType> argTypes;
			for(auto& a : arguments)
			{
				argTypes.push_back(a.type);
				validators.push_back(a.validator);
			}
			aliasFuncDef = constructOpcodeAlias(newAlias, argTypes);
		}
		
		FunctionModifier::FunctionModifier(ast::Lexer::ParsedFunctionModifier newModifier, const OpcodeAlias& newOpcodeAlias) : modifier(newModifier), opcodeAlias(newOpcodeAlias) { }
		
		
		
		
		
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
			{ isGenericCondition,	"say:",							"scratch_say",			{ ast::Lexer::ParsedVariableType::String } },
			{ nullptr,				"say:duration:elapsed:from:",	"scratch_sayDuration",	{ ast::Lexer::ParsedVariableType::String, ast::Lexer::ParsedVariableType::Real } }
		};
		
		const std::vector<FunctionModifier> functionModifiers =
		{
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnGreenFlag,
				OpcodeAlias(nullptr, "whenGreenFlag", "scratch_onGreenFlag")
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnKeyPressed,
				OpcodeAlias(nullptr, "whenKeyPressed", "scratch_onKeyPressed", {
					{
						ast::Lexer::ParsedVariableType::String,
						[](Object* targetObject, std::shared_ptr<ast::Value> arg)
						{
							std::string keyStr(boost::get<std::string>(std::static_pointer_cast<ast::RValueValue>(arg)->getValue()));
							if(keyStr == "any"  ||  keyStr == "space"  ||  keyStr == "up arrow"  ||  keyStr == "down arrow"  ||  keyStr == "right arrow"  ||  keyStr == "left arrow")
								return;
							if(keyStr.size() == 1  &&  ((keyStr[0] >= 'a'  &&  keyStr[0] <= 'z')  ||  (keyStr[0] >= '0'  &&  keyStr[0] <= '9')))
								return;
							throw GeneralException("invalid key: '" + keyStr + "'");
						}
					}
				})
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnThisClicked,
				OpcodeAlias(nullptr, "whenClicked", "scratch_onThisClicked")
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnBackdropSwitch,
				OpcodeAlias(nullptr, "whenSceneStarts", "scratch_onBackdropSwitch", {
					{
						ast::Lexer::ParsedVariableType::String,
						[](Object* targetObject, std::shared_ptr<ast::Value> arg)
						{
							std::string costumeNameStr(boost::get<std::string>(std::static_pointer_cast<ast::RValueValue>(arg)->getValue()));
							auto stageObject = targetObject->getParentProjectManager()->getStageObject();
							auto& stageCostumes = stageObject->getCostumes();
							if(std::find_if(stageCostumes.begin(), stageCostumes.end(), [&](auto c) { return (c->getName() == costumeNameStr); }) == stageCostumes.end())
								throw GeneralException("stage object '" + stageObject->getName() + "' has no costume called '" + costumeNameStr + "'");
						}
					}
				})
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnSensorGreaterThan,
				OpcodeAlias(nullptr, "whenSensorGreaterThan", "scratch_onSensorGreaterThan", {
					{
						ast::Lexer::ParsedVariableType::String,
						[](Object* targetObject, std::shared_ptr<ast::Value> arg)
						{
							std::string sensorStr(boost::get<std::string>(std::static_pointer_cast<ast::RValueValue>(arg)->getValue()));
							if(sensorStr != "loudness"  &&  sensorStr != "timer"  &&  sensorStr != "video motion")
								throw GeneralException("invalid sensor: '" + sensorStr + "'");
						}
					},
					ast::Lexer::ParsedVariableType::Int
				})
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnReceive,
				OpcodeAlias(nullptr, "whenIReceive", "scratch_onReceive", { ast::Lexer::ParsedVariableType::String })
			),
			FunctionModifier
			(
				ast::Lexer::ParsedFunctionModifier::OnClone,
				OpcodeAlias(isGenericCondition, "whenCloned", "scratch_onClone")
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
