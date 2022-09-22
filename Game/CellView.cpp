#include "CellView.h"

void CellView::cellDraw(Cell& cell)
{
	switch (cell.getType()) {
	case WALL:
		printf("%c", 'X');
		break;
	case SPACE:
		printf("%c", ' ');
		break;
	case CHEST:
		printf("%c", 'o');
		break;
	default:
		printf("%c", '?');
		break;
	}
	

}
