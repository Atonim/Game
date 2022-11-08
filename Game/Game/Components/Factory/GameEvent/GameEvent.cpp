#include "GameEvent.h"

Event* GameEvent::createEvent() {
	return new WinEvent;
}
Event* GameEvent::createSecEvent() {
	return new LoseEvent;
}
