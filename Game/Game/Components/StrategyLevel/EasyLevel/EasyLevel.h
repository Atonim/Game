#pragma once
#include "../ILevelStrategy.h"
#include "../../LevelGenerator/LevelGenerator.h"
#include "../../Rules/FieldSize/FieldSizeRule.h"
#include "../../Rules/HeroSpawn/HeroSpawnRule.h"
#include "../../Rules/KeysSpawn/KeysSpawnEz.h"
#include "../../Rules/ShrineSpawn/ShrineSpawnRule.h"
#include "../../Rules/TrapsSpawn/TrapsSpawnEz.h"
#include "../../Rules/WallsSpawn/WallsSpawnEz.h"
#include "../../Rules/ShrineSpawn/ShrineSpawnEz.h"
class EasyLevel : public ILevelStrategy
{
	LevelGenerator<ShrineSpawnEz<9>, HeroSpawnRule<0, 1>, FieldSizeRule<9>,  KeysSpawnEz<0>,   TrapsSpawnEz<9>, WallsSpawnEz<9>> levelGenerator;
public:
	Field* generateLevel() override;
};

//проверка на недопустимые значения
//порядок не важен