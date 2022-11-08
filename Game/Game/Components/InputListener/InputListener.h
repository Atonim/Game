#pragma once
#include <cstdio>
#include <conio.h>
#include "../../Mytypes.h"
#include "../Mediator/BaseComponent.h"
#include "../Mediator/CommandMediator.h"
class InputListener : public BaseComponent
{
	eDirection command = STOP;
public:
	void listen();
	
};

