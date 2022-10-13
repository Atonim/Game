#pragma once
#include "PlayerEvent.h"
class CureEvent : public PlayerEvent
{
public:
	void trigger() override;
	CureEvent(Player*);
};

