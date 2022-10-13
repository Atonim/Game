#include "LoseFactory.h"

LoseFactory::LoseFactory(int* gameover) : GEFactory(gameover) {}

LoseEvent* LoseFactory::createEvent()
{
	return new LoseEvent(_gameover);
}
