#pragma once
#include <iostream>
#include "../../Game/Components/Field/Field.h"
#include "../../Game/Components/Logger/LogObserver/ILogSubject.h"
#include "../../Game/Components/Logger/LogObserver/ILogObserver.h"

#include <list>
#include "../../Game/Components/Logger/LogLevels/ErrLevel.h"
class FieldSettings : public ILogSubject
{
	std::list<ILogObserver*> list_observer_;
public:
	enum type { FIELD, WALLS, OVERHEAL };
	void start(Field&);
	void attach(ILogObserver*) override;
	void detach(ILogObserver*) override;
	void notify(LogLevel*, int) override;
};

