#include "Logic.h"

void Logic::start(Field& field, Player& player)
{
	int playerX = field.getPlayerX();
	int playerY = field.getPlayerY();
	Cell* playerCell = field.getMatrix().at(playerY).at(playerX);
	//AbstractEventFactory* factory;
	//������� ����������� �������
	if (player.getHealth() == 0) {
		this->notify();
		GameEvent* factory = new GameEvent();
		factory->createSecEvent()->trigger();
		delete factory;
	}
	if (player.getKeys() == field.getKeys()) {
		this->notify();
		GameEvent* factory = new GameEvent;
		factory->createEvent()->trigger();
		delete factory;
	}
	//������� ������� ��� �������
	if (playerCell->getType() == SHRINE) {
		PlayerEvent* factory = new PlayerEvent(&player);
		factory->createThirdEvent()->trigger();
		delete factory;
	}
	if (playerCell->getType() == CHEST) {
		PlayerEvent* factory = new PlayerEvent(&player);
		factory->createEvent()->trigger();
		delete factory;
		//��������� ������
		FieldEvent* changecell = new FieldEvent(&field);
		changecell->createEvent()->trigger();
		delete changecell;
	}
	if (playerCell->getType() == TRAP) {
		PlayerEvent* factory = new PlayerEvent(&player);
		factory->createSecEvent()->trigger();
		delete factory;
	}//���������� � ������ ������� 
	
	
}

void Logic::notify()
{
	std::list<IObserver*>::iterator iterator = list_observer_.begin();
	while (iterator != list_observer_.end()) {
		(*iterator)->update();
		++iterator;
	}
}

void Logic::attach(IObserver* observer)
{
	list_observer_.push_back(observer);
}

void Logic::detach(IObserver* observer)
{
	list_observer_.remove(observer);
}
