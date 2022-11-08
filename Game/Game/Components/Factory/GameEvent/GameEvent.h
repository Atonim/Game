#pragma once
#include "../AbstractEventFactory.h"
#include "../../Events/Event.h"
#include "../../Events/WinEvent/WinEvent.h"
#include "../../Events/LoseEvent/LoseEvent.h"

class GameEvent : public AbstractEventFactory
{
public:
	Event* createEvent() override;
	Event* createSecEvent();
};

