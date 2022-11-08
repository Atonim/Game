#include "KeyEvent.h"
KeyEvent::KeyEvent(Player* player) : player_(player) {}
void KeyEvent::trigger()
{
	player_->keysPlus();
}

