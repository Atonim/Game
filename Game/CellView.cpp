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
	case TRAP:
		printf("%c", 'o');
		break;
	case SHRINE:
		printf("%c", '*');
		break;
	default:
		printf("%c", '?');
		break;
	}
	

}
