#pragma once
#include "IObserver.h"
#include "Controller.h"
#include "ILogSubject.h"
#include "GameLevel.h"
class LevelRunner : public IObserver, public ILogSubject
{
	enum type { START, OVER, PAUSED, SAVED };
	bool process;
	std::list<ISubject*> list_subject_;			//подписки
	std::list<ILogObserver*> list_observer_;	//подписчики
public:
	LevelRunner();
	void removeMeFromAllLists();
	bool getProcess();
	void start();
	void update() override;
	void addSubject(ISubject*);
	void attach(ILogObserver*) override;
	void detach(ILogObserver*) override;
	void notify(LogLevel*, int) override;
};

