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
	//в константном аргументе правил необходимо указать рамер поля, в аргументе расположения игрока - координаты 
	LevelGenerator<ShrineSpawnEz<9>, HeroSpawnRule<1, 7>, FieldSizeRule<9>,  KeysSpawnEz<9>,   TrapsSpawnEz<9>, WallsSpawnEz<9>> levelGenerator;
public:
	Field* generateLevel() override;
};
