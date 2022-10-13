#include "DamageFactory.h"

PlayerEvent* DamageFactory::createEvent()
{
    return new DamageEvent(_player);
}

DamageFactory::DamageFactory(Player* player) : PEFactory(player) {}
