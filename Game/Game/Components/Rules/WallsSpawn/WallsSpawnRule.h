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
	field->setWallsAmount(amount);
	printf("NACAHL STENI\n");
	for (int i = 0; i < field->getSize(); i++) {
		for (int j = 0; j < field->getSize(); j++)
			if (walls[j][i] == 'X') {
				delete(field->getMatrix()->at(j).at(i));
				field->getMatrix()->at(j).at(i) = new Cell(WALL);
			}
				
	}
	printf("KONEZ\n");

}
