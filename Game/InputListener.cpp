#include "InputListener.h"

void InputListener::listen(int& gameover)
{
	dir = STOP;
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameover = 0;
			break;
		}
	}
}

int InputListener::getDir()
{
	return dir;
}


