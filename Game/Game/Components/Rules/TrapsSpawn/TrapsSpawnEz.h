#pragma once
#include "../../Field/Field.h"

template <int amount>
class TrapsSpawnEz
{
	std::vector<std::vector<char>> traps = {
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ','X',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};
public:
	void establish(Field*);
};

template<int amount>
void TrapsSpawnEz<amount>::establish(Field* field)
{
	field->setTrapsAmount(amount);

	for (int i = 0; i < field->getSize(); i++) {
		for (int j = 0; j < field->getSize(); j++)
			if (traps[j][i] == 'X') {
				delete(field->getMatrix()->at(j).at(i));
				field->getMatrix()->at(j).at(i) = new Cell(TRAP);
			}

	}
}