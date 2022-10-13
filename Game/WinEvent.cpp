#include "WinEvent.h"

WinEvent::WinEvent(int* gameover) : GameEvent(gameover) {};
void WinEvent::trigger()
{
	*_gameover = 0;
	WinWindow window;
	window.run();
}
;
