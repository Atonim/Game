#include "Logic.h"

void Logic::start(Field& field, Player& player)
{
	int playerX = field.getPlayerX();
	int playerY = field.getPlayerY();
	Cell* playerCell = field.getMatrix().at(playerY).at(playerX);
	//AbstractEventFactory* factory;
	//фабрика глобального события
	if (player.getHealth() == 0) {
		this->notify(new InfoLevel, DEATH);
		this->notify();
		GameEvent* factory = new GameEvent();
		factory->createSecEvent()->trigger();
		delete factory;
	}
	else if (player.getKeys() == field.getKeys()) {
		this->notify(new InfoLevel, VICTORY);
		this->notify();
		GameEvent* factory = new GameEvent;
		factory->createEvent()->trigger();
		delete factory;
	}
	else {
		//фабрика события над игроком
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
			//изменение клетки
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

void Logic::notify(LogLevel* messagelvl, int key)
{
	std::list<ILogObserver*>::iterator iterator = list_logobserver_.begin();
	while (iterator != list_logobserver_.end()) {
		(*iterator)->update(messagelvl, key);
		++iterator;
	}
	delete messagelvl;
}
