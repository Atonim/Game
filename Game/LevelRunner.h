#pragma once
#include "IObserver.h"
#include "Controller.h"
class LevelRunner : public IObserver
{
	bool process = true;
	std::list<ISubject*> list_subject_;
public:
	void removeMeFromAllLists();
	bool getProcess();
	void update() override;
	void addSubject(ISubject*);
};

