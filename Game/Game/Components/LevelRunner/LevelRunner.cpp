#include "LevelRunner.h"
LevelRunner::LevelRunner() : process(false) {
}
void LevelRunner::removeMeFromAllLists()
{
	std::list<ISubject*>::iterator iterator = list_subject_.begin();
	while (iterator != list_subject_.end()) {
		(*iterator)->detach(this);
		++iterator;
	}
}

void LevelRunner::start() {
	process = true;
	this->notify(new GameLevel, START);
}
bool LevelRunner::getProcess()
{
	return process;
}

void LevelRunner::update()
{
	process = false;
	this->notify(new GameLevel, OVER);
}

void LevelRunner::addSubject(ISubject* subject) {
	list_subject_.push_back(subject);
	subject->attach(this);
}

void LevelRunner::attach(ILogObserver* observer)
{
	list_observer_.push_back(observer);
}

void LevelRunner::detach(ILogObserver* observer)
{
	list_observer_.remove(observer);
}

void LevelRunner::notify(LogLevel* messagelvl, int key)
{
	std::list<ILogObserver*>::iterator iterator = list_observer_.begin();
	while (iterator != list_observer_.end()) {
		//тут вызываем методы обсервера 
		(*iterator)->update(messagelvl, key);
		++iterator;
	}
	delete messagelvl;
}
