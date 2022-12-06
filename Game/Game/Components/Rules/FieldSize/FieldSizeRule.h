#pragma once
#include "../../Field/Field.h"
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
	else
		printf("[ERROR] Inappropriate field size");
}
