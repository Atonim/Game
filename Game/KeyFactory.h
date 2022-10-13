#pragma once
#include "Player.h"
#include "PEFactory.h"
#include "KeyEvent.h"
class KeyFactory : public PEFactory
{
public:
	PlayerEvent* createEvent() override;
	KeyFactory(Player*);
};

