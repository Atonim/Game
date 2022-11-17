#pragma once
#include <cstdio>
#include <conio.h>
#include <vector>
#include "../../Mytypes.h"
#include "../Mediator/BaseComponent.h"
#include "../Mediator/CommandMediator.h"
#include "../ControlReader/IControlReader.h"
class InputListener : public BaseComponent
{
	eDirection command = STOP;
	std::vector<IControlReader*>readers;
public:
	void listen();
	void addControlReader(IControlReader*);
	~InputListener();
};

