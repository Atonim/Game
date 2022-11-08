#pragma once
#include "../Event.h"
#include "../../Window/GameEndWindow/WinWindow.h"
class WinEvent : public Event
{
public:
	void trigger() override;
};

