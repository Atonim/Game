#pragma once
#include "PlayerEvent.h"
class DamageEvent : public PlayerEvent
{
public:
	void trigger() override;
};

