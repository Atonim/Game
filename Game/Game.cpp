#include "Game.h"

void Game::run()
{
	Field* field = new Field;
	InputListener* listener = new InputListener;
	Controller* controller = new Controller(field);
	CommandMediator* commandMediator = new CommandMediator(controller, listener);
	Logic* logic = new Logic;
	LevelRunner* levelRunner = new LevelRunner;
	levelRunner->addSubject(controller);		//оформл€ем подписку на контроллер
	levelRunner->addSubject(logic);				//оформл€ем подписку на событи€
	Player* player = new Player;
	Menu menu;
	FieldView fieldView;
	menu.start(*field);
	while (levelRunner->getProcess()) {			//пока метод класса возвращает true
		fieldView.DrawField(field, player);		// рисуем поле
		listener->listen();						// считывание нажати€ клавиш (последующее исполнение команд)
		logic->start(*field, *player);			// запуск событий
	}
	delete player;
	delete logic;
	delete levelRunner;
	delete commandMediator;
	delete controller;
	delete listener;
	delete field;
}
