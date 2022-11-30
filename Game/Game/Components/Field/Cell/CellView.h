#pragma once
#include <iostream>
#include "Cell.h"
#include "../Field.h"
#include "../../../../Menu/Menu.h"
class CellView : public Menu
{
public:
	void cellDraw(Cell&);
};

 