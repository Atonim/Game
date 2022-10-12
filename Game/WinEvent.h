#pragma once
#include "GameEvent.h"
class WinEvent : public GameEvent
{
public:
	void trigger() override;
};

