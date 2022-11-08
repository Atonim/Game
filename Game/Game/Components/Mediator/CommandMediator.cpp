#include "CommandMediator.h"

CommandMediator::CommandMediator(Controller* controller, InputListener* listener) : controller_(controller), listener_(listener) {
	this->controller_->set_mediator(this);
	this->listener_->set_mediator(this);
	this->command = STOP;
}

void CommandMediator::notify()
{
	this->controller_->run(command);
}

void CommandMediator::setCommand(eDirection command) {
	this->command = command;
}
