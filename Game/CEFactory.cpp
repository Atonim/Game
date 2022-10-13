#include "CEFactory.h"

CEFactory::CEFactory(Cell* cell) : _cell(cell) {}

void CEFactory::trigger()
{
	CellEvent* event = this->createEvent();
	event->trigger();
	delete event;
}