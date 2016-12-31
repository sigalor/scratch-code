/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/ManifestDefinitions.cpp
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



#include "ManifestDefinitions.hpp"



namespace fs = boost::filesystem;
namespace op = sc::ObjectParams;

namespace sc
{
	namespace ManifestDefinitions
	{
		namespace ProjectManagerManifest
		{
			const ManifestEntry<ProjectManager> rootEntry(ManifestStructure<ProjectManager>(
			{
				ManifestEntry<ProjectManager>
				(
					"username",
					mep::Type::String,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](ProjectManager* projMgr) { return "your_username"; },
						/* processor */			[](ProjectManager* projMgr, const mep::TypeVariant& val) { projMgr->setUsername(boost::get<std::string>(val)); }
					)
				),
				ManifestEntry<ProjectManager>
				(
					"title",
					mep::Type::String,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](ProjectManager* projMgr) { return projMgr->getProjectPath().filename().string(); },
						/* processor */			[](ProjectManager* projMgr, const mep::TypeVariant& val) { projMgr->setTitle(boost::get<std::string>(val)); }
					)
				),
				ManifestEntry<ProjectManager>
				(
					"binariesDirectoryPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](ProjectManager* projMgr) { return "bin"; },
						/* processor */			[](ProjectManager* projMgr, const mep::TypeVariant& val)
												{
													std::string binariesPath(boost::get<std::string>(val));
													if(projMgr->getIsInitialization())
														fs::create_directories(projMgr->getProjectPath() / binariesPath);
													projMgr->setBinariesDirectoryPath(binariesPath);
												}
					)
				),
				ManifestEntry<ProjectManager>
				(
					"generatedFilesDirectoryPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](ProjectManager* projMgr) { return "gen"; },
						/* processor */			[](ProjectManager* projMgr, const mep::TypeVariant& val)
												{
													std::string generatedFilesPath(boost::get<std::string>(val));
													if(projMgr->getIsInitialization())
														fs::create_directories(projMgr->getProjectPath() / generatedFilesPath);
													projMgr->setGeneratedFilesDirectoryPath(generatedFilesPath);
												}
					)
				),
				ManifestEntry<ProjectManager>
				(
					"objectsDirectoryPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](ProjectManager* projMgr) { return "objects"; },
						/* processor */			[](ProjectManager* projMgr, const mep::TypeVariant& val)
												{
													std::string objectsPath(boost::get<std::string>(val));
													if(projMgr->getIsInitialization())
														fs::create_directories(projMgr->getProjectPath() / objectsPath);
													projMgr->setObjectsDirectoryPath(objectsPath);
												}
					)
				)
			}));
			const ManifestEntryValue<bool> rootEntryValueBase(rootEntry);
		}
	
		namespace ObjectManifest
		{
			const ManifestEntry<Object> rootEntry(ManifestStructure<Object>(
			{
				ManifestEntry<Object>
				(
					"objectName",
					mep::Type::String,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj) { return obj->getObjectPath().filename().string(); },
						/* processor */			[](Object* obj, const mep::TypeVariant& val) { obj->setName(boost::get<std::string>(val)); }
					)
				),
				ManifestEntry<Object>
				(
					"type",
					mep::Type::String,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj)
												{
													if(obj->getIsInitialization())
														return op::typeToJSONString(obj->getTypeForInitialization());
													return op::typeToJSONString(op::Type::Generic);
												},
						/* processor */			[](Object* obj, const mep::TypeVariant& val)
												{
													obj->setType(op::jsonStringToType(boost::get<std::string>(val)));
												}
					)
				),
				ManifestEntry<Object>
				(
					"costumesDirectoryPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj) { return "costumes"; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)
												{
													std::string costumesPath(boost::get<std::string>(val));
													if(obj->getIsInitialization())
														fs::create_directories(obj->getObjectPath() / costumesPath);		//fs::create_directories acts like "mkdir -p", i.e. it creates missing parents as well
													obj->setCostumesDirectoryPath(costumesPath);
												}
					)
				),
				ManifestEntry<Object>
				(
					"scriptsDirectoryPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj) { return "scripts"; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)
												{
													std::string scriptsPath(boost::get<std::string>(val));
													if(obj->getIsInitialization())
														fs::create_directories(obj->getObjectPath() / scriptsPath);
													obj->setScriptsDirectoryPath(scriptsPath);
												}
					)
				),
				ManifestEntry<Object>
				(
					"soundsDirectoryPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj) { return "sounds"; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)
												{
													std::string soundsPath(boost::get<std::string>(val));
													if(obj->getIsInitialization())
														fs::create_directories(obj->getObjectPath() / soundsPath);
													obj->setSoundsDirectoryPath(soundsPath);
												}
					)
				),
				ManifestEntry<Object>
				(
					"penLayerPath",
					mep::Type::String,
					mep::Importance::Optional,
					std::make_tuple
					(
						/* condition */			[](Object* obj) { return (obj->getType() == op::Type::Stage); },	//pen layer is only needed when the object is a stage (otherwise it's ignored and "alternative" and "processor" will NOT be executed)
						/* alternative */		[](Object* obj) { return "penLayer/penLayer.png"; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)
												{
													fs::path penLayerPath(obj->getObjectPath() / boost::get<std::string>(val));		//because of the upper "condition", no checking for "obj->getType() == op::Type::Stage" is necessary
													if(obj->getIsInitialization())
													{
														fs::create_directories(penLayerPath.parent_path());
														Utilities::writePlainPNGToFile(penLayerPath, 480, 360, 0, 0, 0, 0);
													}
													obj->setPenLayerPath(boost::get<std::string>(val));
													obj->setPenLayer(std::make_shared<Costume>(penLayerPath));
												}
					)
				),
				ManifestEntry<Object>
				(
					"costumes",
					mep::Type::Array,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */				nullptr,
						/* preProcessor */			nullptr,
						/* elementPreProcessor */	[](Object* obj)
													{
														obj->addCostume(std::make_shared<Costume>());
														obj->setCurrentlyProcessedCostume(obj->getCostumes().back());
														obj->getCurrentlyProcessedCostume()->setResourceIndex(obj->getCostumes().size() - 1);
													},
						/* elementPostProcessor */	nullptr,
						/* postProcessor */			[](Object* obj)
													{
														if(obj->getIsInitialization())
														{
															using namespace rapidjson;
												
															//if initialization is currently working, the object should not have any costumes yet
															if(obj->getCostumes().size() != 0)
																throw GeneralException("number of costumes before initialization needs to be 0");
												
															op::Type					objectType = obj->getType();
															std::string					newCostumeFilename = (objectType==op::Type::Stage ? "backdrop1.png" : (objectType==op::Type::Generic ? "costume1.png" : "error.png"));
															fs::path					newCostumePath(obj->getCostumesDirectoryPath() / newCostumeFilename);
															Value						newCostumeEntry(kObjectType);
															Document::AllocatorType&	alloc = obj->getManifest().GetAllocator();
													
															//create generic costumes (white fullscreen for stage, red square for generic)
															if(objectType == op::Type::Stage)
																Utilities::writePlainPNGToFile(newCostumePath, 480, 360, 255, 255, 255, 255);
															else if(objectType == op::Type::Generic)
																Utilities::writePlainPNGToFile(newCostumePath, 100, 100, 255, 0, 0, 255);
													
															//add an entry for the new costume to the manifest
															newCostumeEntry.AddMember("path", Value(newCostumeFilename.c_str(), alloc), alloc);
															obj->getManifest()["costumes"].PushBack(newCostumeEntry, alloc);
													
															//load the new costume as if it would have been a regular one that also needs to be pre-processed
															//"rootEntry" always means "sc::ManifestDefinitions::ObjectManifest::rootEntry" in this context
															ManifestEntryValue<bool>& costumesEntryValue = obj->getPredefinedValues().getEntry("costumes");
															costumesEntryValue.addArrayEntry(false);
															rootEntry.children.getEntry("costumes").elementPreProcessor(obj);
															obj->getCostumes().back()->loadFromPath(newCostumePath);
															rootEntry.children.validateJSON(obj, obj->getManifest()["costumes"][0], alloc, rootEntry.children.getEntry("costumes").children, obj->getManifestPath(), costumesEntryValue.children.back(), false, true, false);
													
															//output final info message (do not use "obj->getName()" here, as the "ProjectManager::addObject" function sets the desired name later)
															std::cerr << "successfully added costume '" << obj->getCostumes().back()->getName() << "' to object at '" << fs::relative(obj->getObjectPath()).string() << "'" << std::endl;
														}
														obj->checkResourceNameUniqueness("costumes", obj->getCostumes());
													}
					),
					ManifestStructure<Object>(
					{
						ManifestEntry<Object>
						(
							"path",
							mep::Type::String,
							mep::Importance::Required,
							std::make_tuple
							(
								/* condition */			nullptr,
								/* alternative */		nullptr,
								/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->loadFromPath(obj->getCostumesDirectoryPath() / boost::get<std::string>(val)); }
							)
						),
						ManifestEntry<Object>
						(
							"name",
							mep::Type::String,
							mep::Importance::Optional,
							std::make_tuple
							(
								/* condition */			nullptr,
								/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedCostume()->getResourcePath().stem().string(); },
								/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->setName(boost::get<std::string>(val)); }
							)
						),
						ManifestEntry<Object>
						(
							"rotationCenterX",
							mep::Type::Integer,
							mep::Importance::Optional,
							std::make_tuple
							(
								/* condition */			nullptr,
								/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedCostume()->getWidth() / 2; },
								/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->setRotationCenterX(boost::get<int>(val)); }
							)
						),
						ManifestEntry<Object>
						(
							"rotationCenterY",
							mep::Type::Integer,
							mep::Importance::Optional,
							std::make_tuple
							(
								/* condition */			nullptr,
								/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedCostume()->getHeight() / 2; },
								/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedCostume()->setRotationCenterY(boost::get<int>(val)); }
							)
						)
					})
				),
				ManifestEntry<Object>
				(
					"sounds",
					mep::Type::Array,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */				nullptr,
						/* preProcessor */			nullptr,
						/* elementPreProcessor */	[](Object* obj)
													{
														obj->addSound(std::make_shared<Sound>());
														obj->setCurrentlyProcessedSound(obj->getSounds().back());
														obj->getCurrentlyProcessedSound()->setResourceIndex(obj->getSounds().size() - 1);
													},
						/* elementPostProcessor */	nullptr,
						/* postProcessor */			[](Object* obj)
													{
														obj->checkResourceNameUniqueness("sounds", obj->getSounds());
													}
					),
					ManifestStructure<Object>(
					{
						ManifestEntry<Object>
						(
							"path",
							mep::Type::String,
							mep::Importance::Required,
							std::make_tuple
							(
								/* condition */			nullptr,
								/* alternative */		nullptr,
								/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedSound()->loadFromPath(obj->getSoundsDirectoryPath() / boost::get<std::string>(val)); }
							)
						),
						ManifestEntry<Object>
						(
							"name",
							mep::Type::String,
							mep::Importance::Optional,
							std::make_tuple
							(
								/* condition */			nullptr,
								/* alternative */		[](Object* obj)									{ return obj->getCurrentlyProcessedSound()->getResourcePath().stem().string(); },
								/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->getCurrentlyProcessedSound()->setName(boost::get<std::string>(val)); }
							)
						)
					})
				),
				ManifestEntry<Object>
				(
					"currentCostumeIndex",
					mep::Type::Integer,
					mep::Importance::OptionalWithWarning,
					std::make_tuple
					(
						/* condition */			nullptr,
						/* alternative */		[](Object* obj)									{ return 0; },
						/* processor */			[](Object* obj, const mep::TypeVariant& val)	{ obj->setCurrentCostumeIndex(boost::get<int>(val)); }		//all costumes are available at this point
					)
				)
			}));
			const ManifestEntryValue<bool> rootEntryValueBase(rootEntry);
		}
	}
}
