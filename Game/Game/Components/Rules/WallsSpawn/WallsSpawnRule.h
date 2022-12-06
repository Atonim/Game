#pragma once
#include "../../Field/Field.h"

template <int amount>
class WallsSpawnRule
{
	std::vector<std::vector<char>> walls = {
		{' ',' ',' ',' ','X',' ','X',' ','X',' ',' ','X','X','X','X'},
		{' ','X','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ','X'},
		{' ','X',' ',' ','X',' ',' ',' ',' ',' ','X',' ','X',' ','X'},
		{' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','X'},
		{'X',' ','X','X',' ','X',' ',' ',' ',' ','X',' ','X',' ',' '},
		{' ',' ',' ','X',' ',' ','X',' ','X',' ',' ',' ',' ',' ','X'},
		{' ','X',' ','X',' ','X','X',' ','X','X',' ','X','X','X','X'},
		{' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		{' ','X',' ',' ',' ','X','X',' ','X','X',' ','X',' ',' ','X'},
		{'X',' ',' ',' ',' ',' ','X',' ','X',' ',' ','X',' ',' ',' '},
		{' ',' ','X',' ','X',' ',' ',' ',' ','X',' ','X','X',' ',' '},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' '},
		{'X',' ','X',' ','X',' ','X',' ','X',' ',' ',' ',' ','X',' '},
		{'X',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ','X','X',' '},
		{'X','X','X','X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' '},
	};
public:
	void establish(Field*);
};

template<int amount>
void WallsSpawnRule<amount>::establish(Field* field)
{
	if (amount) {
		field->setWallsAmount(amount);

		for (int i = 0; i < field->getSize(); i++) {
			for (int j = 0; j < field->getSize(); j++)
				if (walls[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						printf("[ERROR] Wrong walls generation");
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(WALL);
				}

		}
	}
	else
		printf("[ERROR] Wrong walls generation");
}
