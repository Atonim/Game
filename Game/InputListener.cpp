#include "InputListener.h"

void InputListener::listen()
{
	command = STOP;
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			command = UP;
			break;
		case 'a':
			command = LEFT;
			break;
		case 's':
			command = DOWN;
			break;
		case 'd':
			command = RIGHT;
			break;
		case 'x':
			command = EXIT;
			break;
		case 'g':
			command = ACTIVITY;
			break;
		}
	}
	CommandMediator* mediator = dynamic_cast<CommandMediator*>(mediator_);
	mediator->setCommand(command);
	mediator->notify();
}


