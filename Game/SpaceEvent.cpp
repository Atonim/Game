#include "SpaceEvent.h"
SpaceEvent::SpaceEvent(Field* field) : field_ (field) {}
void SpaceEvent::trigger()
{
	int PlayerX = field_->getPlayerX();
	int PlayerY = field_->getPlayerY();
	Cell* playerCell = field_->getMatrix().at(PlayerY).at(PlayerX);
	if (playerCell->getType() == CHEST)
		playerCell->changeType();
}


