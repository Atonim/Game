#pragma once
#include "../ILevelStrategy.h"
#include "../../LevelGenerator/LevelGenerator.h"
#include "../../Rules/FieldSize/FieldSizeRule.h"
#include "../../Rules/HeroSpawn/HeroSpawnRule.h"
#include "../../Rules/KeysSpawn/KeysSpawnEz.h"
#include "../../Rules/ShrineSpawn/ShrineSpawnRule.h"
#include "../../Rules/TrapsSpawn/TrapsSpawnEz.h"
#include "../../Rules/WallsSpawn/WallsSpawnEz.h"
class EasyLevel : public ILevelStrategy
{
	LevelGenerator<HeroSpawnRule<1, 7>, ShrineSpawnRule<5,3>, KeysSpawnEz<3>, FieldSizeRule<9>, TrapsSpawnEz<1>, WallsSpawnEz<35>> levelGenerator;
public:
	Field* generateLevel() override;
};

//проверка на недопустимые значения
//порядок не важен