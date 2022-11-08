#pragma once
#include "../AbstractEventFactory.h"
#include "../../Field/Field.h"
#include "../../Events/SpaceEvent/SpaceEvent.h"
class FieldEvent : public AbstractEventFactory {
protected:
	Field* _field = nullptr;
public:
	FieldEvent(Field*);
	Event* createEvent() override;
};