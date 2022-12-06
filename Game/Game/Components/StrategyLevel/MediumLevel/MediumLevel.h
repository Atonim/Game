#pragma once
#include "../ILevelStrategy.h"
#include "../../LevelGenerator/LevelGenerator.h"
#include "../../Rules/FieldSize/FieldSizeRule.h"
#include "../../Rules/HeroSpawn/HeroSpawnRule.h"
#include "../../Rules/KeysSpawn/KeysSpawnRule.h"
#include "../../Rules/ShrineSpawn/ShrineSpawnRule.h"
#include "../../Rules/TrapsSpawn/TrapsSpawnRule.h"
#include "../../Rules/WallsSpawn/WallsSpawnRule.h"
class MediumLevel : public ILevelStrategy
{
	LevelGenerator<FieldSizeRule<15>, HeroSpawnRule<0, 0>, ShrineSpawnRule<9>, KeysSpawnRule<5>, TrapsSpawnRule<3>, WallsSpawnRule<78>> levelGenerator;
public:
	Field* generateLevel() override;
};

