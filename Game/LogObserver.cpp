#include "LogObserver.h"
void LogObserver::check(IMessage* messagelvl, int key)
{
	//проверка на то что мы реально отслеживаем этот уровень логирования
	//если да, то получаем предложение
	const char* message = messagelvl->get_message(key);
}
void LogObserver::update(const char* message)
{
	//тут передаем сообщение в нужный принтер
	std::list<Logger*>::iterator iterator = list_loggers_.begin();
	while (iterator != list_loggers_.end()) {
		(*iterator)->print(message);
		++iterator;
	}
}
void LogObserver::addSubject(ILogSubject* subject) {
	list_subject_.push_back(subject);
	subject->attach(this);
}
void LogObserver::addLogger(Logger* logger)
{
	list_loggers_.push_back(logger);
}
void LogObserver::addLogLvl(LogLevel* lvl)
{
	list_loglvl_.push_back(lvl);
}
void LogObserver::removeMeFromAllLists()
{
	std::list<ILogSubject*>::iterator iterator = list_subject_.begin();
	while (iterator != list_subject_.end()) {
		(*iterator)->detach(this);
		++iterator;
	}
}

LogObserver::~LogObserver()
{
	for (auto elem : list_loggers_)
		delete elem;
	for (auto elem : list_loglvl_)
		delete elem;
}
