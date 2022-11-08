#include "Cell.h"

Cell::Cell() : myType(SPACE) {}
Cell::Cell(cellType type) : myType(type) {}
//Cell::Cell(const Cell& obj)
//{
//    this->myType = obj.myType;
//    this->player = obj.player;
//    this->playerEvent = obj.playerEvent;
//}
//Cell& Cell::operator=(const Cell& obj)
//{
//    this->myType = obj.myType;
//    this->player = obj.player;
//    this->playerEvent = obj.playerEvent;
//    return *this;
//}
Cell:: ~Cell() {}

void Cell::playerContact()
{
    /*if (myType == CHEST)
        cellEvent.trigger();*/
}

cellType Cell::getType()
{
    return myType;
}

void Cell::changeType()
{
    myType = SPACE;
}

