#pragma once
#include "AbstractEventFactory.h"
#include "Event.h"
#include "WinEvent.h"
#include "LoseEvent.h"

class GameEvent : public AbstractEventFactory
{
public:
	Event* createEvent() override;
	Event* createSecEvent();
};

