#pragma once
#include "../../Field/Field.h"
#include <conio.h>
template <int size>
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

template<int size>
void TrapsSpawnEz<size>::establish(Field* field)
{
	if (size == traps.size()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (traps[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						system("cls");
						printf("[ERROR] Inappropriate traps generation");
						_getch();
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(TRAP);
				}

		}
	}
	else {
		system("cls");
		printf("[ERROR] Inappropriate traps generation");
		_getch();
	}
	
}
