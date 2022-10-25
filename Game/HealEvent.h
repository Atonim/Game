#pragma once
#include "Event.h"
#include "Player.h"
class HealEvent : public Event
{
	Player* player_ = nullptr;
public:
	void trigger() override;
	HealEvent(Player*);
};

