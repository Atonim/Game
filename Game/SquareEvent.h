#pragma once
#include "CellEvent.h"
class SquareEvent : public CellEvent
{
public:
	void trigger() override;
};

