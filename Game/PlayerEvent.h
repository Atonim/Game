#pragma once
#include "Event.h"
#include "Player.h"
class PlayerEvent : public Event
{
public:
	void trigger() override = 0;
	PlayerEvent(Player*);
protected:
	Player* _player = nullptr;
};

