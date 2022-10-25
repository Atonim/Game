#pragma once
#include "Event.h"
#include "LoseWindow.h"
class LoseEvent : public Event
{
public:
	void trigger() override;
};

