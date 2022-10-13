#pragma once
#include "GEFactory.h"
#include "LoseEvent.h"
class LoseFactory : public GEFactory
{
public:
	LoseFactory(int*);
	LoseEvent* createEvent() override;
};

