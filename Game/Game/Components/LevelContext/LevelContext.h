#pragma once
#include "../StrategyLevel/ILevelStrategy.h"
#include "../Field/Field.h"
class LevelContext
{
	ILevelStrategy* strategy;
public:
	LevelContext(ILevelStrategy*);
	~LevelContext();
	void setStrategy(ILevelStrategy*);
	Field* createLevel();
};

