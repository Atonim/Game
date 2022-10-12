#include "KeyEvent.h"

void KeyEvent::trigger()
{
	_player->keysPlus();
}
KeyEvent::KeyEvent(Player* player) : PlayerEvent(player) {}
