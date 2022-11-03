#pragma once
#include "ILogObserver.h"
#include <list>
#include "Logger.h"
#include "IMessage.h"
#include "ILogSubject.h"
#include "Mytypes.h"
class LogObserver : public ILogObserver
{
	std::list<Logger*> list_loggers_;			//все используемые логгеры (принтеры)
	std::list<ILogSubject*> list_subject_;
	logLevel priority = INFOLVL;							//приоретет логлевелов
public:
	//void check();
	void update(LogLevel*, int) override;
	void setPriority(logLevel);
	void addSubject(ILogSubject*);
	void addLogger(Logger*);
	//void removeLogger();
	void removeMeFromAllLists();
	~LogObserver();
};

