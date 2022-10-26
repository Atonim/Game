#pragma once
#include <cstdio>
#include <conio.h>
#include "Mytypes.h"
#include "BaseComponent.h"
#include "CommandMediator.h"
class InputListener : public BaseComponent
{
	eDirection command = STOP;
public:
	void listen();
	
};

