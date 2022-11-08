#include "DamageEvent.h"

void DamageEvent::trigger()
{
	player_->damage();
}

DamageEvent::DamageEvent(Player* player) : player_ (player) {}
