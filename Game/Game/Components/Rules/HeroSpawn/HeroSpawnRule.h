#pragma once
#include "../../Field/Field.h"
template <int x, int y>
class HeroSpawnRule
{
public:
	void establish(Field*);
};

template<int x, int y>
void HeroSpawnRule<x, y>::establish(Field* field)
{
	
	if (x < field->getSize() && y < field->getSize() && x >= 0 && y >= 0)
		field->setHeroSpawn(x, y);
	else
		printf("[ERROR] Wrong hero spawn coordinates");
}
