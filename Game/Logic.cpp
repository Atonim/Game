#include "Logic.h"

void Logic::start(int dir, Field& field, Player& player, int& gameover)
{
	if (player.getHealth() == 0) {
		LoseFactory* factory = new LoseFactory(&gameover);
		factory->trigger();
		delete factory;
	}
	if (player.getKeys() == 5) {
		WinFactory* factory = new WinFactory(&gameover);
		factory->trigger();
		delete factory;
	}
	//������� �������
	if (field.getMatrix().at(field.getPlayerY()).at(field.getPlayerX())->getType() == SHRINE) {
		CureFactory* factory = new CureFactory(&player);
		factory->trigger();
		delete factory;
	}

	////�������� �� ���������
	//if (player.getHealth() == 0) {
	//	LoseEvent* event = new LoseEvent(&gameover);
	//	event->trigger();
	//	delete event;
	//}
	////�������� �� ������
	//if (player.getKeys() >= 6) {
	//	WinEvent* event = new WinEvent(&gameover);
	//	event->trigger();
	//	delete event;
	//}
	////�������
	//if (!(rand() % 100)) {
	//	CureEvent* event = new CureEvent(&player);
	//	event->trigger();
	//	delete event;
	//}

	int newX, newY;	//���������� ��� ����� �������� ��������� ������
	switch (dir) {  //��������� ����������� �������� � ������� ������ � ������ �������
	case STOP:
		break;
	case UP:
		newY = field.getPlayerY() - 1;
		if (newY < 0)
			newY = field.getSize() - 1;
		if (field.getMatrix().at(newY).at(field.getPlayerX())->getType())
			field.movePlayerY(newY);
		break;
	case LEFT:
		newX = field.getPlayerX() - 1;
		if (newX < 0)
			newX = field.getSize() - 1;
		if (field.getMatrix().at(field.getPlayerY()).at(newX)->getType())
		field.movePlayerX(newX);
		break;
	case DOWN:
		newY = field.getPlayerY() + 1;
		if (newY > field.getSize() - 1)
			newY = 0;
		if (field.getMatrix().at(newY).at(field.getPlayerX())->getType())
			field.movePlayerY(newY);
		break;
	case RIGHT:
		newX = field.getPlayerX() + 1;
		if (newX > field.getSize() - 1)
			newX = 0;
		if (field.getMatrix().at(field.getPlayerY()).at(newX)->getType())
			field.movePlayerX(newX);
		break;
	}

	//������� ������� � ������
	if (field.getMatrix().at(field.getPlayerY()).at(field.getPlayerX())->getType() == CHEST) {
		KeyFactory* factory = new KeyFactory(&player);
		factory->trigger();
		delete factory;
	}
	if (field.getMatrix().at(field.getPlayerY()).at(field.getPlayerX())->getType() == TRAP) {
		DamageFactory* factory = new DamageFactory(&player);
		factory->trigger();
		delete factory;
	}

	////��������� ���� � ������� ��
	//if (field.getMatrix().at(field.getPlayerY()).at(field.getPlayerX())->getType() == CHEST) {
	//	KeyEvent* event = new KeyEvent(&player);
	//	event->trigger();
	//	delete event;
	//	DamageEvent* event1 = new DamageEvent(&player);
	//	event1->trigger();
	//	delete event1;
	//}


	////field.matrix().at(field.currentPlayerY()).at(field.currentPlayerX())->playerContact(); //������ ��������� �� ������
	////������ ������ ��� �� �������
	//SpaceEvent* event = new SpaceEvent(field.getMatrix().at(field.getPlayerY()).at(field.getPlayerX()));
	//event->trigger();
	//delete event;
	
	//������� ��������� ������
	SpaceFactory* factory = new SpaceFactory(field.getMatrix().at(field.getPlayerY()).at(field.getPlayerX()));
	factory->trigger();
	delete factory;
	
}
