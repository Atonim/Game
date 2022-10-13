#pragma once
#include "Event.h"

class GameEvent : public Event
{
public:
	void trigger() override = 0;
	GameEvent(int*);
protected:
	int* _gameover = nullptr;
};

