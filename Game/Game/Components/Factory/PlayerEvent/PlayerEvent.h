#pragma once
#include "../AbstractEventFactory.h"
#include "../../Events/Event.h"
#include "../../Player/Player.h"
#include "../../Events/KeyEvent/KeyEvent.h"
#include "../../Events/DamageEvent/DamageEvent.h"
#include "../../Events/HealEvent/HealEvent.h"
class PlayerEvent : public AbstractEventFactory
{
	Player* _player = nullptr;
public:
	Event* createEvent() override;
	Event* createSecEvent();
	Event* createThirdEvent();
	PlayerEvent(Player*);
};

