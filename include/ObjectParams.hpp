/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ObjectParams.hpp
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



#include <string>
#include <functional>

#include "GeneralException.hpp"



namespace sc
{
	class Object;

	namespace ObjectParams
	{
		enum class Type
		{
			Invalid,
			Stage,
			Generic
		};
		
		enum class RotationStyle
		{
			Invalid,
			Normal,
			LeftRight,
			None
		};
		
		extern const std::function<bool(Object*)>				isStageCondition, isGenericCondition;
		
		const std::string										typeToReadableString(Type type);
		const std::string										typeToJSONString(Type type);
		Type													jsonStringToType(const std::string& typeStr);
		const std::string										rotationStyleToJSONString(RotationStyle rotationStyle);
		RotationStyle											jsonStringToRotationStyle(const std::string& rotationStyleStr);
	}
}



//I hate to do this, but circular dependencies are horrible.
#include "Object.hpp"
