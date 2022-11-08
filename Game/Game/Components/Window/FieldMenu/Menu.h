#pragma once
#include <iostream>
#include "../../Field/Field.h"
#include "../../Logger/LogObserver/ILogSubject.h"
#include "../../Logger/LogObserver/ILogObserver.h"
#include <list>
#include "../../Logger/LogLevels/ErrLevel.h"
class Menu : public ILogSubject
{
	std::list<ILogObserver*> list_observer_;
public:
	enum type { FIELD, WALLS, OVERHEAL };
	void start(Field&);
	void attach(ILogObserver*) override;
	void detach(ILogObserver*) override;
	void notify(LogLevel*, int) override;
};

