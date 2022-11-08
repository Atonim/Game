#pragma once
#include "../Event.h"
#include "../../Window/GameEndWindow/LoseWindow.h"
class LoseEvent : public Event
{
public:
	void trigger() override;
};

