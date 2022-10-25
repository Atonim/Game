#pragma once
#include <list>
#include "BaseComponent.h"
#include "ISubject.h"
#include "Mytypes.h"
#include "Field.h"
class Controller : public BaseComponent, public ISubject
{
	Field* field_;
	std::list<IObserver*> list_observer_;
public:
	Controller(Field*);
	void run(eDirection);
	void notify() override;
	void attach(IObserver*) override;
	void detach(IObserver*) override;
};

