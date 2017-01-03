/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/ManifestEntryParams.cpp
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



#include "ManifestEntryParams.hpp"



namespace sc
{
	namespace ManifestEntryParams
	{
		const std::string typeToReadableString(Type type)
		{
			switch(type)
			{
				case Type::Boolean	: return "boolean";
				case Type::Integer	: return "integer";
				case Type::Float	: return "floating-point value";
				case Type::String	: return "string";
				case Type::Array	: return "array";
				case Type::Object	: return "object";
				default				: return "(unknown)";
			}
		}
	}
}
