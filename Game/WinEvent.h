#pragma once
#include "Event.h"
#include "WinWindow.h"
class WinEvent : public Event
{
public:
	void trigger() override;
};

