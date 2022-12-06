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
	//в константном аргументе правил необходимо указать рамер поля, в аргументе расположения игрока - координаты 
	LevelGenerator<FieldSizeRule<15>, HeroSpawnRule<0, 0>, ShrineSpawnRule<15>, KeysSpawnRule<15>, TrapsSpawnRule<15>, WallsSpawnRule<15>> levelGenerator;
public:
	Field* generateLevel() override;
};

