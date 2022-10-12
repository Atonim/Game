#pragma once
#include "GameEvent.h"
class LoseEvent : public GameEvent
{
public:
	void trigger() override;
};

