#pragma once
#include "GEFactory.h"
#include "WinEvent.h"
class WinFactory : public GEFactory
{
public:
	WinFactory(int*);
	WinEvent* createEvent() override;
};

