#include "LogObserver.h"

void LogObserver::update(LogLevel* messagelvl, int key)
{
	if (messagelvl->check(priority)){
		const char* message = messagelvl->get_sentence(key);
		std::list<Logger*>::iterator iterator = list_loggers_.begin();
		while (iterator != list_loggers_.end()) {
			(*iterator)->print(message);
			++iterator;
		}
	}
}
void LogObserver::setPriority(logLevel priority)
{
	this->priority = priority;
}
void LogObserver::addSubject(ILogSubject* subject) {
	list_subject_.push_back(subject);
	subject->attach(this);
}
void LogObserver::addLogger(Logger* logger)
{
	list_loggers_.push_back(logger);
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
}
