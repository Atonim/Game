#include "LoseEvent.h"

void LoseEvent::trigger()
{
	*_gameover = 0;
	LoseWindow window;
	window.run();
}

LoseEvent::LoseEvent(int* gameover) : GameEvent(gameover) {}
