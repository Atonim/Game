#pragma once
#include "Mediator.h"
class BaseComponent
{
protected:
	Mediator* mediator_ = nullptr;
public:
	BaseComponent(Mediator*);
	BaseComponent() = default;
	void set_mediator(Mediator*);
};

