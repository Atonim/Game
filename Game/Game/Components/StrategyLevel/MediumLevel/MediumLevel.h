#pragma once
#include "../ILevelStrategy.h"
#include "../../LevelGenerator/LevelGenerator.h"
class MediumLevel : public ILevelStrategy
{
	LevelGenerator<> levelGenerator;
public:
	Field* generateLevel() override;
};

