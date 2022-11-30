#include "LevelContext.h"

LevelContext::LevelContext(ILevelStrategy* strategy = nullptr) : strategy(strategy) {}

LevelContext::~LevelContext()
{
	delete this->strategy;
}

void LevelContext::setStrategy(ILevelStrategy* strategy)
{
	delete this->strategy;
	this->strategy = strategy;
}

Field* LevelContext::createLevel()
{
	return this->strategy->generateLevel();
}
