#pragma once
#include <vector>
#include "../../Field/Field.h"
template <int amount>
class KeysSpawnEz
{
	std::vector<std::vector<char>> keys{
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ','X',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ','X',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ','X',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};
public:
	void establish(Field*);
};

template <int amount>
void KeysSpawnEz<amount>::establish(Field* field)
{
	field->setKeysAmount(amount);

	for (int i = 0; i < field->getSize(); i++) {
		for (int j = 0; j < field->getSize(); j++)
			if (keys[j][i] == 'X') {
				delete(field->getMatrix()->at(j).at(i));
				field->getMatrix()->at(j).at(i) = new Cell(CHEST);
			}
	}
}
