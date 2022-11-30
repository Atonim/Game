#include "Logic.h"

void Logic::start(Field& field, Player& player)
{
	std::pair<int, int> playerXY = field.getPlayerXY();
	Cell* playerCell = field.getMatrix()->at(playerXY.second).at(playerXY.first);
	//AbstractEventFactory* factory;
	//������� ����������� �������
	if (player.getHealth() == 0) {
		this->notify(new InfoLevel, DEATH);
		this->notify();
		GameEvent* factory = new GameEvent();
		factory->createSecEvent()->trigger();
		delete factory;
	}
	else if (player.getKeys() == field.getKeysAmount()) {
		this->notify(new InfoLevel, VICTORY);
		this->notify();
		GameEvent* factory = new GameEvent;
		factory->createEvent()->trigger();
		delete factory;
	}
	else {
		//������� ������� ��� �������
		if (playerCell->getType() == SHRINE) {
			this->notify(new InfoLevel, HEAL);
			PlayerEvent* factory = new PlayerEvent(&player);
			factory->createThirdEvent()->trigger();
			delete factory;
		}
		if (playerCell->getType() == CHEST) {
			this->notify(new InfoLevel, KEY);
			PlayerEvent* factory = new PlayerEvent(&player);
			factory->createEvent()->trigger();
			delete factory;
			//��������� ������
			this->notify(new InfoLevel, CELL);
			FieldEvent* changecell = new FieldEvent(&field);
			changecell->createEvent()->trigger();
			delete changecell;
		}
		if (playerCell->getType() == TRAP) {
			this->notify(new InfoLevel, DAMAGE);
			PlayerEvent* factory = new PlayerEvent(&player);
			factory->createSecEvent()->trigger();
			delete factory;
		}//���������� � ������ ������� 
	}
	
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

void Logic::attach(ILogObserver* observer)
{
	list_logobserver_.push_back(observer);
}

void Logic::detach(IObserver* observer)
{
	list_observer_.remove(observer);
}

void Logic::detach(ILogObserver* observer)
{
	list_logobserver_.remove(observer);
}

void Logic::notify(LogLevel* messagelvl, int key)
{
	std::list<ILogObserver*>::iterator iterator = list_logobserver_.begin();
	while (iterator != list_logobserver_.end()) {
		(*iterator)->update(messagelvl, key);
		++iterator;
	}
	delete messagelvl;
}
