#include "BaseComponent.h"

BaseComponent::BaseComponent(Mediator* mediator) : mediator_(mediator) {}
void BaseComponent::set_mediator(Mediator* mediator) {
	this->mediator_ = mediator;
}
