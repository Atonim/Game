#include "SpaceEvent.h"

void SpaceEvent::trigger()
{
	if (_cell->getType() == CHEST)
		_cell->changeType();
}

SpaceEvent::SpaceEvent(Cell* cell) : CellEvent(cell) {}
