#pragma once
#include "../Event.h"
#include "../../Player/Player.h"
class DamageEvent : public Event
{
	Player* player_;
public:
	void trigger() override;
	DamageEvent(Player*);
};

