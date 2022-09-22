#pragma once
#include "Player.h"
#include "Mytypes.h"
class Event
{
public:
	void virtual trigger(Player&, cellType&) = 0;
};
