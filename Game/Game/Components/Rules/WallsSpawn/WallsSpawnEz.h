#pragma once
#include "../../Field/Field.h"
#include <conio.h>
template <int size>
class WallsSpawnEz
{
	std::vector<std::vector<char>> walls = {
		{'X',' ','X','X',' ','X','X',' ','X'},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'X',' ','X',' ','X',' ','X',' ','X'},
		{'X',' ','X',' ','X',' ',' ',' ','X'},
		{' ',' ','X',' ','X','X','X',' ',' '},
		{'X',' ','X',' ',' ',' ',' ',' ','X'},
		{'X',' ','X','X','X','X','X',' ','X'},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'X',' ','X','X',' ','X','X',' ','X'},
	};
public:
	void establish(Field*);
};

template<int size>
void WallsSpawnEz<size>::establish(Field* field)
{
	if (size == walls.size()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (walls[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						system("cls");
						printf("[ERROR] Inappropriate walls generation");
						_getch();
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(WALL);
				}

		}
	}
	else {
		system("cls");
		printf("[ERROR] Inappropriate walls generation");
		_getch();
	}
}


