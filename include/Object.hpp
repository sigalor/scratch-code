/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Object.hpp
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
#include <vector>
#include <memory>

#include "Costume.hpp"
#include "Sound.hpp"



namespace sc
{
	class Object
	{
		private:
			std::string											name;
			std::vector<std::shared_ptr<Costume>>				costumes;
			std::vector<std::shared_ptr<Sound>>					sounds;
	
		public:
			Object();
			Object(const std::string& newName);
			
			const std::string&									getName();
			std::vector<std::shared_ptr<Costume>>				getCostumes();
			std::vector<std::shared_ptr<Sound>>					getSounds();
			void												addCostume(std::shared_ptr<Costume> newCostume);
			void												addSound(std::shared_ptr<Sound> newSound);
	};
}
