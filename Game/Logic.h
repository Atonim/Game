#pragma once
#include <list>
#include "Player.h"
#include "Field.h"
#include "AbstractEventFactory.h"
#include "PlayerEvent.h"
#include "GameEvent.h"
#include "FieldEvent.h"
#include "ISubject.h"
#include "ILogSubject.h"
#include "InfoLevel.h"
class Logic : public ISubject, public ILogSubject
{
	std::list<IObserver*> list_observer_;		// для остального
	std::list<ILogObserver*> list_logobserver_;	// для логов
	enum infoType { DEATH, DAMAGE, HEAL, KEY, PRAYING, CELL, VICTORY };
	enum errType { FIELD, WALLS, OVERHEAL };
public:
	void start(Field&, Player&);
	void notify() override;
	void attach(IObserver*) override;
	void attach(ILogObserver*) override;
	void detach(IObserver*) override;
	void detach(ILogObserver*) override;
	void notify(LogLevel*, int) override;
};

