#include "FieldView.h"

void FieldView::DrawField(Field& field) {
	Sleep(300);
	system("cls");
	int height = field.height();
	int width = field.width();
	for (int i = 0; i < width + 2; i++)
		printf("%c", '#');
	printf("%c", '\n');

	for (int i = 0; i < height; i++) {
		printf("%c", '#');
		for (int j = 0; j < width; j++) {;
			if (j == field.currentPlayerX() && i == field.currentPlayerY())
				printf("%c", '0');
			else 
				cellView.cellDraw(*(field.matrix().at(i).at(j)));
		}
		printf("%c", '#');
		printf("%c", '\n');
	}

	for (int i = 0; i < width + 2; i++)
		printf("%c", '#');
	printf("%c", '\n');
	printf("%s %d", "\nKeys Found:", field.getPlayer()->getKeys());
	printf("%c", '\n');
}