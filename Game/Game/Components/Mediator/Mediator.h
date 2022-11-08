#pragma once
#include "../../Mytypes.h"
class BaseComponent;
class Mediator
{
public:
	virtual void notify() = 0;
};

