#include "FieldEvent.h"
FieldEvent::FieldEvent(Field* field) : _field(field) {}
Event* FieldEvent::createEvent() {
	return new SpaceEvent(_field);
}