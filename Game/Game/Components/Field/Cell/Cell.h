#pragma once
#include <vector>
#include "../../../Mytypes.h"
class Cell
{
	cellType myType;
public:
	
	Cell();
	Cell(cellType);
	/*Cell(const Cell&);
	Cell& operator =(const Cell&);*/
	~Cell();
	void playerContact();
	cellType getType();
	void changeType();
};

