#pragma once
#include "Event.h"
class CellEvent :public Event
{
public:
	void trigger(Player&, cellType&) override;
};
