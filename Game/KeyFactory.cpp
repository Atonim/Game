#include "KeyFactory.h"

PlayerEvent* KeyFactory::createEvent()
{
    return new KeyEvent(_player);
}

KeyFactory::KeyFactory(Player* player) : PEFactory(player) {}


