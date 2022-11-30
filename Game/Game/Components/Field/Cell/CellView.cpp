#include "CellView.h"

void CellView::cellDraw(Cell& cell)
{
	switch (cell.getType()) {
	case WALL:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY);
		printf("%c", 'X');
		break;
	case SPACE:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("%c", ' ');
		break;
	case CHEST:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE);
		printf("%c", 'o');
		break;
	case TRAP:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE);
		printf("%c", 'o');
		break;
	case SHRINE:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("%c", '+');
		break;
	default:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE);
		printf("%c", '?');
		break;
	}
	

}
