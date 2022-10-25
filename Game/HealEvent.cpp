#include "HealEvent.h"

void HealEvent::trigger()
{
	if (player_->getHealth() < 100)
	player_->treatment();
}

HealEvent::HealEvent(Player* player) : player_ (player) {}
