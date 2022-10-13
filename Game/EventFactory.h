#pragma once
#include "Event.h"
class EventFactory
{
public:
	virtual Event* createEvent() = 0;
	void trigger();
};

