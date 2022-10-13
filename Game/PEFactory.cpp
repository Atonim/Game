#include "PEFactory.h"

PEFactory::PEFactory(Player* player) : _player(player) {}

void PEFactory::trigger()
{
	PlayerEvent* event = this->createEvent();
	event->trigger();
	delete event;
}
