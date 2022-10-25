#include "LevelRunner.h"

void LevelRunner::removeMeFromAllLists()
{
	std::list<ISubject*>::iterator iterator = list_subject_.begin();
	while (iterator != list_subject_.end()) {
		(*iterator)->detach(this);
		++iterator;
	}
}

bool LevelRunner::getProcess()
{
	return process;
}

void LevelRunner::update()
{
	process = false;
}

void LevelRunner::addSubject(ISubject* subject) {
	list_subject_.push_back(subject);
	subject->attach(this);
}