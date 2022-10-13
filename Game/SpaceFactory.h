#pragma once
#include "Cell.h"
#include "CEFactory.h"
#include "SpaceEvent.h"
class SpaceFactory : public CEFactory
{
public:
	SpaceFactory(Cell*);
	SpaceEvent* createEvent() override;
};

