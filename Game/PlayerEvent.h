#pragma once
#include "AbstractEventFactory.h"
#include "Event.h"
#include "Player.h"
#include "KeyEvent.h"
#include "DamageEvent.h"
#include "HealEvent.h"
class PlayerEvent : public AbstractEventFactory
{
	Player* _player = nullptr;
public:
	Event* createEvent() override;
	Event* createSecEvent();
	Event* createThirdEvent();
	PlayerEvent(Player*);
};

