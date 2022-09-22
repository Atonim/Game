#pragma once
#include <vector>
#include "Player.h"
#include "CellEvent.h"
#include "Mytypes.h"
class Cell
{
	Player player;
	CellEvent cellEvent;
	cellType myType;
public:
	
	Cell();
	Cell(Player&, cellType);
	/*Cell(const Cell&);
	Cell& operator =(const Cell&);*/
	~Cell();
	void playerContact();
	cellType getType();
	void changeType(cellType);
};

