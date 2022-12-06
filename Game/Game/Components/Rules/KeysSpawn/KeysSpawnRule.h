#pragma once
#include <utility>
#include <vector>
#include <conio.h>
#include "../../Field/Field.h"
template <int size>
class KeysSpawnRule
{
	int amount = 0;
	std::vector<std::vector<char>> keys {
		{'-','-','-','-','-','-','-','X','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','X','-','-','-','-','-','-','-'},
		{'X','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','X','-','-','-','-','X'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	};
public:
	void establish(Field*);
};

template <int size>
void KeysSpawnRule<size>::establish(Field* field)
{
	if (size == keys.size()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (keys[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						system("cls");
						printf("[ERROR] Inappropriate keys generation");
						_getch();
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(CHEST);
					amount++;
				}
		}
		field->setKeysAmount(amount);
	}
	else {
		system("cls");
		printf("[ERROR] Inappropriate keys generation");
		_getch();
	}
	
}
