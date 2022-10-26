#include "Logic.h"

void Logic::start(Field& field, Player& player)
{
	int playerX = field.getPlayerX();
	int playerY = field.getPlayerY();
	Cell* playerCell = field.getMatrix().at(playerY).at(playerX);
	//AbstractEventFactory* factory;
	//фабрика глобального события
	if (player.getHealth() == 0) {
		this->notify(new InfoMessage, DEATH);
		this->notify();
		GameEvent* factory = new GameEvent();
		factory->createSecEvent()->trigger();
		delete factory;
	}
	else if (player.getKeys() == field.getKeys()) {
		this->notify(new InfoMessage, VICTORY);
		this->notify();
		GameEvent* factory = new GameEvent;
		factory->createEvent()->trigger();
		delete factory;
	}
	else {
		//фабрика события над игроком
		if (playerCell->getType() == SHRINE) {
			this->notify(new InfoMessage, HEAL);
			PlayerEvent* factory = new PlayerEvent(&player);
			factory->createThirdEvent()->trigger();
			delete factory;
		}
		if (playerCell->getType() == CHEST) {
			this->notify(new InfoMessage, KEY);
			PlayerEvent* factory = new PlayerEvent(&player);
			factory->createEvent()->trigger();
			delete factory;
			//изменение клетки
			this->notify(new InfoMessage, CELL);
			FieldEvent* changecell = new FieldEvent(&field);
			changecell->createEvent()->trigger();
			delete changecell;
		}
		if (playerCell->getType() == TRAP) {
			this->notify(new InfoMessage, DAMAGE);
			PlayerEvent* factory = new PlayerEvent(&player);
			factory->createSecEvent()->trigger();
			delete factory;
		}//передавать в клетку событие 
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

void Logic::notify(IMessage* messagelvl, int key)
{
	std::list<ILogObserver*>::iterator iterator = list_logobserver_.begin();
	while (iterator != list_logobserver_.end()) {
		//тут вызываем методы обсервера 
		const char* message = messagelvl->get_message(key);
		(*iterator)->update(message);
		++iterator;
	}
}
