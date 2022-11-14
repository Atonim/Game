#include "Game.h"

void Game::run(LogObserver* observer, Field* field)
{
	

	


	InputListener* listener = new InputListener;
	Controller* controller = new Controller(field);
	CommandMediator* commandMediator = new CommandMediator(controller, listener);
	Logic* logic = new Logic;

	LevelRunner* levelRunner = new LevelRunner;
	levelRunner->addSubject(controller);		//оформляем подписку на контроллер
	levelRunner->addSubject(logic);				//оформляем подписку на события


	Player* player = new Player;

	
	//observer->addSubject(&field_settings);			//оформляем подписку логгера на меню
	observer->addSubject(logic);				//на логику событий
	observer->addSubject(levelRunner);			//на процесс цикла игры

	FieldView fieldView;
	

	
	



	levelRunner->start();
	while (levelRunner->getProcess()) {			//пока метод класса возвращает true
		fieldView.DrawField(field, player);		// рисуем поле
		listener->listen();						// считывание нажатия клавиш (последующее исполнение команд)
		logic->start(*field, *player);			// запуск событий
	}


	delete player;
	delete logic;
	delete levelRunner;
	delete commandMediator;
	delete controller;
	delete listener;

	//delete errMes;
	//delete gameMes;
	//delete infoMes;
}
