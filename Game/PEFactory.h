#pragma once
#include "Player.h"
#include "PlayerEvent.h"
class PEFactory
{
public:
	virtual PlayerEvent* createEvent() = 0;
	PEFactory(Player*);
	void trigger();
protected:
	Player* _player = nullptr;
};

