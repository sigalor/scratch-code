/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ManifestDefinitions.hpp
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



#include <iostream>
#include <string>
#include <tuple>
#include <memory>
#include <boost/filesystem.hpp>
#include <boost/variant.hpp>
#include <rapidjson/document.h>

#include "ManifestEntry.hpp"
#include "ManifestEntryParams.hpp"
#include "ManifestEntryValue.hpp"
#include "ManifestStructure.hpp"
#include "ProjectManager.hpp"
#include "Object.hpp"
#include "ObjectParams.hpp"
#include "Costume.hpp"
#include "Sound.hpp"
#include "GeneralException.hpp"
#include "Utilities.hpp"



namespace sc
{
	class ProjectManager;
	class Object;

	namespace ManifestDefinitions
	{
		namespace ProjectManagerManifest
		{
			extern const ManifestEntry<ProjectManager>				rootEntry;
			extern const ManifestEntryValue<bool>					rootEntryValueBase;
		}
	
		namespace ObjectManifest
		{
			extern const ManifestEntry<Object>						rootEntry;
			extern const ManifestEntryValue<bool>					rootEntryValueBase;
		}
	}
}
