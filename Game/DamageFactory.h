#pragma once
#include "Player.h"
#include "PEFactory.h"
#include "DamageEvent.h"
class DamageFactory : public PEFactory
{
public:
	PlayerEvent* createEvent() override;
	DamageFactory(Player*);
};

