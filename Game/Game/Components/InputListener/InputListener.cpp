#include "InputListener.h"

void InputListener::listen()
{
	command = STOP;
	if (_kbhit()) {
		char key = _getch();
		for (auto elem : readers) {
			command = elem->read(key);
		}
		
	}
	CommandMediator* mediator = dynamic_cast<CommandMediator*>(mediator_);
	mediator->setCommand(command);
	mediator->notify();
}

void InputListener::addControlReader(IControlReader* reader)
{
	readers.push_back(reader);
}

InputListener::~InputListener()
{
	for (auto elem : readers)
		delete elem;
}


