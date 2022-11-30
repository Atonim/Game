#pragma once
#include "../Field/Field.h"
class ILevelStrategy
{
public:
	virtual Field* generateLevel() = 0;
};

