#pragma once
#include <iostream>
#include "Field.h"
#include "ILogSubject.h"
#include "ILogObserver.h"
#include <list>
#include "ErrLevel.h"
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

