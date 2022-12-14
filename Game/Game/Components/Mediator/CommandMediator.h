#pragma once

#include "../InputListener/InputListener.h"
#include "../Controller/Controller.h"
class InputListener;
class CommandMediator : public Mediator
{
	Controller* controller_;
	InputListener* listener_;
	eDirection command;
public:
	CommandMediator(Controller*, InputListener*);
	void notify();
	void setCommand(eDirection);
};

