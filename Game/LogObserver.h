#pragma once
#include "ILogObserver.h"
#include <list>
#include "Logger.h"
#include "IMessage.h"
#include "ILogSubject.h"
class LogObserver : public ILogObserver
{
	std::list<Logger*> list_loggers_;			//все используемые логгеры (принтеры)
	std::list<LogLevel*> list_loglvl_;			//все используемые логлевелы
	std::list<ILogSubject*> list_subject_;
public:
	void check(IMessage*, int);
	void update(const char* message) override;
	void addSubject(ILogSubject*);
	void addLogger(Logger*);
	void addLogLvl(LogLevel*);
	void removeLogger();
	void removeMeFromAllLists();
	~LogObserver();
};

