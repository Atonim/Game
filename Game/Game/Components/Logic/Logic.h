#pragma once
#include <list>
#include <utility>
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Factory/AbstractEventFactory.h"
#include "../Factory/PlayerEvent/PlayerEvent.h"
#include "../Factory/GameEvent/GameEvent.h"
#include "../Factory/FieldEvent/FieldEvent.h"
#include "../Observer/ISubject.h"
#include "../Logger/LogObserver/ILogSubject.h"
#include "../Logger/LogLevels/InfoLevel.h"
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

