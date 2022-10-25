#pragma once
#include "Event.h"
class AbstractEventFactory {
public:
	virtual Event* createEvent() = 0;
};