#pragma once
#include "PlayerEvent.h"
class KeyEvent : public PlayerEvent
{
public:
	void trigger() override;
	KeyEvent(Player*);
};

