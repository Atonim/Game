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
	if (amount) {
		field->setTrapsAmount(amount);

		for (int i = 0; i < traps.size(); i++) {
			for (int j = 0; j < traps.size(); j++)
				if (traps[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						printf("[ERROR] Wrong traps generation");
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(TRAP);
				}

		}
	}
	else
		printf("[ERROR] Wrong traps generation");
	
}
