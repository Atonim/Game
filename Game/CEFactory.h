#pragma once
#include "Cell.h"
#include "CellEvent.h"
class CEFactory
{
public:
	virtual CellEvent* createEvent() = 0;
	CEFactory(Cell*);
	void trigger();
protected:
	Cell* _cell = nullptr;
};

