#include "SpaceFactory.h"

SpaceFactory::SpaceFactory(Cell* cell) : CEFactory(cell) {}

SpaceEvent* SpaceFactory::createEvent()
{
    return new SpaceEvent(_cell);
}
