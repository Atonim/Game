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
	if (x < field->getSize(), y < field->getSize() && x >= 0 && y >= 0) {
		if (field->getMatrix()->at(y).at(x)->getType() != SPACE) {
			printf("[ERROR] Wrong shrine generation");
			return;
		}
		delete(field->getMatrix()->at(y).at(x));
		field->getMatrix()->at(y).at(x) = new Cell(SHRINE);
	}
	else
		printf("[ERROR] Wrong shrine generation");
	
}
