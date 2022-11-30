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
	field->setSize(size);
	
	for (int i = 0; i < size; i++) {
		field->getMatrix()->emplace_back(std::vector<Cell*>());
		for (int j = 0; j < size; j++)
			field->getMatrix()->back().emplace_back(new Cell(SPACE));
	}
}
