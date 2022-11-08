#include "PlayerEvent.h"

PlayerEvent::PlayerEvent(Player* player) : _player(player) {}

Event* PlayerEvent::createEvent() {
	return new KeyEvent(_player);
}
Event* PlayerEvent::createSecEvent() {
	return new DamageEvent(_player);
}
Event* PlayerEvent::createThirdEvent() {
	return new HealEvent(_player);
}
