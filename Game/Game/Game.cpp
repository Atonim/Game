#include "Game.h"

void Game::run(LogObserver* observer, IControlReader* control_reader, LevelContext* context)
{
	
	
	Field* field = context->createLevel();
	FieldChecker check;
	if (!check.check(field)) {					//�������� ���������� ��������� ����
		delete field;
		return;
	}
	InputListener* listener = new InputListener;
	listener->addControlReader(control_reader);
	Controller* controller = new Controller(field);
	CommandMediator* commandMediator = new CommandMediator(controller, listener);
	Logic* logic = new Logic;

	LevelRunner* levelRunner = new LevelRunner;
	levelRunner->addSubject(controller);		//��������� �������� �� ����������
	levelRunner->addSubject(logic);				//��������� �������� �� �������


	Player* player = new Player;

	
	observer->addSubject(logic);				//�� ������ �������
	observer->addSubject(levelRunner);			//�� ������� ����� ����

	FieldView fieldView;
	

	
	



	levelRunner->start();

	
	while (levelRunner->getProcess()) {			//���� ����� ������ ���������� true
		fieldView.DrawField(field, player);		// ������ ����
		listener->listen();						// ���������� ������� ������ (����������� ���������� ������)
		logic->start(*field, *player);			// ������ �������
	}

	delete field;
	delete player;
	delete logic;
	delete levelRunner;
	delete commandMediator;
	delete controller;
	delete listener;
}
