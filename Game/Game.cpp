#include "Game.h"

void Game::run()
{
	Field* field = new Field;
	InputListener* listener = new InputListener;
	Controller* controller = new Controller(field);
	CommandMediator* commandMediator = new CommandMediator(controller, listener);
	Logic* logic = new Logic;
	LevelRunner* levelRunner = new LevelRunner;
	levelRunner->addSubject(controller);		//��������� �������� �� ����������
	levelRunner->addSubject(logic);				//��������� �������� �� �������
	Player* player = new Player;
	Menu menu;
	FieldView fieldView;
	menu.start(*field);
	while (levelRunner->getProcess()) {			//���� ����� ������ ���������� true
		fieldView.DrawField(field, player);		// ������ ����
		listener->listen();						// ���������� ������� ������ (����������� ���������� ������)
		logic->start(*field, *player);			// ������ �������
	}
	delete player;
	delete logic;
	delete levelRunner;
	delete commandMediator;
	delete controller;
	delete listener;
	delete field;
}
