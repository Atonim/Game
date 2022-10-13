#include "GEFactory.h"

GEFactory::GEFactory(int* gameover) : _gameover(gameover) {}

void GEFactory::trigger()
{
	GameEvent* event = this->createEvent();
	event->trigger();
	delete event;
}
