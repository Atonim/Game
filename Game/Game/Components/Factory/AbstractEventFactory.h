#pragma once
#include "../Events/Event.h"
class AbstractEventFactory {
public:
	virtual Event* createEvent() = 0;
};