#pragma once
#include "../../Field/Field.h"
#include <conio.h>
template <int size>
class FieldSizeRule
{
public:
	void establish(Field*);
};

template<int size>
void FieldSizeRule<size>::establish(Field* field)
{
	if (size)
		field->setSize(size);
	else {
		system("cls");
		printf("[ERROR] Inappropriate field size generation");
		_getch();
	}
}
