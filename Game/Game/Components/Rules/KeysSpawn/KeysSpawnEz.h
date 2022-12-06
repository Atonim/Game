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
	if (amount) {
		field->setKeysAmount(amount);

		for (int i = 0; i < keys.size(); i++) {
			for (int j = 0; j < keys.size(); j++)
				if (keys[j][i] == 'X') {
					if (field->getMatrix()->at(j).at(i)->getType() != SPACE) {
						printf("[ERROR] Wrong keys generation");
						return;
					}
					delete(field->getMatrix()->at(j).at(i));
					field->getMatrix()->at(j).at(i) = new Cell(CHEST);
				}
		}
	}
	else
		printf("[ERROR] Wrong keys generation");
	
}
