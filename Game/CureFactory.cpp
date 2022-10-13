#include "CureFactory.h"

PlayerEvent* CureFactory::createEvent()
{
	return new CureEvent(_player);
}

CureFactory::CureFactory(Player* player) : PEFactory(player) {}
