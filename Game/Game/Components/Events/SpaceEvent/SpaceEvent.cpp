#include "SpaceEvent.h"
SpaceEvent::SpaceEvent(Field* field) : field_ (field) {}
void SpaceEvent::trigger()
{
	std::pair<int, int> PlayerXY = field_->getPlayerXY();
	Cell* playerCell = field_->getMatrix()->at(PlayerXY.second).at(PlayerXY.first);
	if (playerCell->getType() == CHEST)
		playerCell->changeType();
}


