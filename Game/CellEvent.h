#pragma once
#include "AbstractEventFactory.h"
#include "Event.h"
#include "Cell.h"
class CellEvent : public AbstractEventFactory
{
public:
	Event* createEvent() override;
	CellEvent(Cell*);
protected:
	Cell* _cell = nullptr;
};
