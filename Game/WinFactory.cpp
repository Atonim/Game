#include "WinFactory.h"

WinFactory::WinFactory(int* gameover) : GEFactory(gameover) {}

WinEvent* WinFactory::createEvent()
{
	return new WinEvent(_gameover);
}
