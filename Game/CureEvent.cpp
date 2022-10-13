#include "CureEvent.h"

void CureEvent::trigger()
{
	if (_player->getHealth() < 100)
	_player->treatment();
}

CureEvent::CureEvent(Player* player) : PlayerEvent(player) {}
