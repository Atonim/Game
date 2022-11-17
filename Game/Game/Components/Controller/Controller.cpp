#include "Controller.h"
Controller::Controller(Field* field) :field_(field) {}

void Controller::run(eDirection command)
{
	int newX, newY;
	switch (command) {  //считываем направление движения и двигаем игрока в нужную сторону
	case STOP:
		break;
	case UP:
		newY = field_->getPlayerY() - 1;
		if (newY < 0)
			newY = field_->getSize() - 1;
		if (field_->getMatrix().at(newY).at(field_->getPlayerX())->getType())
			field_->movePlayerY(newY);
		break;
	case LEFT:
		newX = field_->getPlayerX() - 1;
		if (newX < 0)
			newX = field_->getSize() - 1;
		if (field_->getMatrix().at(field_->getPlayerY()).at(newX)->getType())
			field_->movePlayerX(newX);
		break;
	case DOWN:
		newY = field_->getPlayerY() + 1;
		if (newY > field_->getSize() - 1)
			newY = 0;
		if (field_->getMatrix().at(newY).at(field_->getPlayerX())->getType())
			field_->movePlayerY(newY);
		break;
	case RIGHT:
		newX = field_->getPlayerX() + 1;
		if (newX > field_->getSize() - 1)
			newX = 0;
		if (field_->getMatrix().at(field_->getPlayerY()).at(newX)->getType())
			field_->movePlayerX(newX);
		break;
	
	case EXIT:
		notify();
		break;
	case ABILITY:
		notify();
		break;
	}
}


void Controller::notify() {
	std::list<IObserver*>::iterator iterator = list_observer_.begin();
	while (iterator != list_observer_.end()) {
		(*iterator)->update();
		++iterator;
	}
}

void Controller::attach(IObserver* observer)
{
	list_observer_.push_back(observer);
}

void Controller::detach(IObserver* observer)
{
	list_observer_.remove(observer);
}
