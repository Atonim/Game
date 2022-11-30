#include "Controller.h"
Controller::Controller(Field* field) :field_(field) {}

void Controller::run(eDirection command)
{
	int newX, newY;
	switch (command) {  //считываем направление движения и двигаем игрока в нужную сторону
	case STOP:
		break;
	case UP:
		newY = field_->getPlayerXY().second - 1;
		if (newY < 0)
			newY = field_->getSize() - 1;
		if (field_->getMatrix()->at(newY).at(field_->getPlayerXY().first)->getType())
			field_->movePlayerXY(field_->getPlayerXY().first, newY);
		break;
	case LEFT:
		newX = field_->getPlayerXY().first - 1;
		if (newX < 0)
			newX = field_->getSize() - 1;
		if (field_->getMatrix()->at(field_->getPlayerXY().second).at(newX)->getType())
			field_->movePlayerXY(newX, field_->getPlayerXY().second);
		break;
	case DOWN:
		newY = field_->getPlayerXY().second + 1;
		if (newY > field_->getSize() - 1)
			newY = 0;
		if (field_->getMatrix()->at(newY).at(field_->getPlayerXY().first)->getType())
			field_->movePlayerXY(field_->getPlayerXY().first, newY);
		break;
	case RIGHT:
		newX = field_->getPlayerXY().first + 1;
		if (newX > field_->getSize() - 1)
			newX = 0;
		if (field_->getMatrix()->at(field_->getPlayerXY().second).at(newX)->getType())
			field_->movePlayerXY(newX, field_->getPlayerXY().second);
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
