#pragma once
#include "Player.h"
#include "PEFactory.h"
#include "CureEvent.h"
class CureFactory : public PEFactory
{
public:
	PlayerEvent* createEvent() override;
	CureFactory(Player*);
};

