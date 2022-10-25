#pragma once
#include <list>
#include "Player.h"
#include "Field.h"
#include "AbstractEventFactory.h"
#include "PlayerEvent.h"
#include "GameEvent.h"
#include "FieldEvent.h"
#include "ISubject.h"
class Logic : public ISubject
{
	std::list<IObserver*> list_observer_;
public:
	void start(Field&, Player&);
	void notify() override;
	void attach(IObserver*) override;
	void detach(IObserver*) override;
};

