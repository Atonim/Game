#pragma once
#include "../../Field/Field.h"
template <int x, int y>
class ShrineSpawnRule
{
public:
	void establish(Field*);
};

template<int x, int y>
void ShrineSpawnRule<x, y>::establish(Field* field)
{
	delete(field->getMatrix()->at(y).at(x));
	field->getMatrix()->at(y).at(x) = new Cell(SHRINE);
}
