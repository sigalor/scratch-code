/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/ObjectParams.cpp
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



#include "ObjectParams.hpp"



namespace sc
{
	namespace ObjectParams
	{
		const std::string typeToReadableString(Type type)															//these are the string representations the user shall see in program outputs (which means they may be translated), NOT the ones that are for the JSON file!
		{
			switch(type)
			{
				case Type::Stage	: return "stage";
				case Type::Generic	: return "generic";
				default				: return "(unknown)";
			}
		}
		
		const std::string typeToJSONString(Type type)																//in contrast to "typeToReadableString", these are the type strings for the JSON file (objectManifest.json) which may NOT be translated
		{
			switch(type)
			{
				case Type::Stage	: return "stage";
				case Type::Generic	: return "generic";
				default				: return "error";
			}
		}
		
		Type jsonStringToType(const std::string& typeStr)
		{
			if(typeStr == "stage")
				return Type::Stage;
			else if(typeStr == "generic")
				return Type::Generic;
			throw GeneralException("value '" + typeStr + "' is invalid for an object type");
		}
		
		const std::string rotationStyleToJSONString(RotationStyle rotationStyle)
		{
			switch(rotationStyle)
			{
				case RotationStyle::Normal		: return "normal";
				case RotationStyle::LeftRight	: return "leftRight";
				case RotationStyle::None		: return "none";
				default							: return "error";
			}
		}
		
		RotationStyle jsonStringToRotationStyle(const std::string& rotationStyleStr)
		{
			if(rotationStyleStr == "normal")
				return RotationStyle::Normal;
			else if(rotationStyleStr == "leftRight")
				return RotationStyle::LeftRight;
			else if(rotationStyleStr == "none")
				return RotationStyle::None;
			throw GeneralException("value '" + rotationStyleStr + "' is invalid for an object's rotation style");
		}
	}
}
