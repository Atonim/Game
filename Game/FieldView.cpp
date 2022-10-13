#include "FieldView.h"

void FieldView::DrawField(Field& field, Player& player) {
	Sleep(300);
	system("cls");
	int size = field.getSize();

	for (int i = 0; i < size + 2; i++)
		printf("%c", '#');
	printf("%c", '\n');

	for (int i = 0; i < size; i++) {
		printf("%c", '#');
		for (int j = 0; j < size; j++) {;
			if (j == field.getPlayerX() && i == field.getPlayerY())
				printf("%c", '0');
			else 
				cellView.cellDraw(*(field.getMatrix().at(i).at(j)));
		}
		printf("%c", '#');
		printf("%c", '\n');
	}

	for (int i = 0; i < size + 2; i++)
		printf("%c", '#');
	printf("%c", '\n');

	printf("%s %d", "\nHealth:", player.getHealth());
	printf("%c", '\n');
	printf("%s %d", "\nAvailable Blessings:", player.getGodsBlessing());
	printf("%c", '\n');
	printf("%s %d", "\nKeys Found:", player.getKeys());
	printf("%c", '\n');
}