#pragma once
#include "GameEvent.h"
#include "WinWindow.h"
class WinEvent : public GameEvent
{
public:
	WinEvent(int*);
	void trigger() override;
};

