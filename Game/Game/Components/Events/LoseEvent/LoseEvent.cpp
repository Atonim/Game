#include "LoseEvent.h"

void LoseEvent::trigger()
{
	LoseWindow window;
	window.run();
}

