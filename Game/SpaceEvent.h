#pragma once
#include "CellEvent.h"
#include "Cell.h"
#include "Mytypes.h"
class SpaceEvent : public CellEvent
{
public:
	void trigger() override;
	SpaceEvent(Cell*);
};

