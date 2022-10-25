#pragma once
#include "Event.h"
#include "Player.h"
class KeyEvent : public Event
{
private:
	Player* player_ = nullptr;
public:
	void trigger() override;
	KeyEvent(Player*);
};

