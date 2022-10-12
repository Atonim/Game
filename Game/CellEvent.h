#pragma once
#include "Event.h"
#include "Cell.h"
class CellEvent : public Event
{
public:
	void trigger() override = 0;
	CellEvent(Cell*);
protected:
	Cell* _cell = nullptr;
};
