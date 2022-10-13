#pragma once
#include "GameEvent.h"
#include "LoseWindow.h"
class LoseEvent : public GameEvent
{
public:
	void trigger() override;
	LoseEvent(int*);
};

