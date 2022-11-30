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
	field->setHeroSpawn(x, y);
}
