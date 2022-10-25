#pragma once
#include "AbstractEventFactory.h"
#include "Field.h"
#include "SpaceEvent.h"
class FieldEvent : public AbstractEventFactory {
protected:
	Field* _field = nullptr;
public:
	FieldEvent(Field*);
	Event* createEvent() override;
};