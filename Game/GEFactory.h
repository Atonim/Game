#pragma once
#include "GameEvent.h"
class GEFactory
{
public:
	virtual GameEvent* createEvent() = 0;
	GEFactory(int*);
	void trigger();
protected:
	int* _gameover = nullptr;
};

