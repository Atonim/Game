#include "DamageEvent.h"

void DamageEvent::trigger()
{
	_player->damage();
}

DamageEvent::DamageEvent(Player* player) : PlayerEvent(player) {}
