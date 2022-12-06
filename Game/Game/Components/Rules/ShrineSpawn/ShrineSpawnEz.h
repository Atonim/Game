#pragma once
#include "../../Field/Field.h"
#include <conio.h>
template <int size>
class ShrineSpawnEz
{
	std::vector<std::vector<char>> shrine = {
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ','X',' ',' ',' '},
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
void ShrineSpawnEz<size>::establish(Field* field)
{
	if (size == shrine.size()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (shrine[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						system("cls");
						printf("[ERROR] Inappropriate shrine generation");
						_getch();
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(SHRINE);
				}
		}
	}
	else {
		system("cls");
		printf("[ERROR] Inappropriate shrine generation");
		_getch();
	}

}

