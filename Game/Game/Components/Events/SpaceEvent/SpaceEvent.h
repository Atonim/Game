#pragma once
#include "../Event.h"
#include "../../Field/Field.h"
#include "../../../Mytypes.h"
class SpaceEvent : public Event
{
	Field* field_ = nullptr;
public:
	void trigger() override;
	SpaceEvent(Field*);
};

