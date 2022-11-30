#include "FieldView.h"

void FieldView::DrawField(Field* field, Player* player) {
	Sleep(300);
	system("cls");
	int size = field->getSize();

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (int i = 0; i < size + 2; i++)
		printf("%c", '#');
	printf("%c", '\n');

	for (int i = 0; i < size; i++) {
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("%c", '#');
		for (int j = 0; j < size; j++) {;
		if (j == field->getPlayerXY().first && i == field->getPlayerXY().second) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("%c", '0');
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else 
				cellView.cellDraw(*(field->getMatrix()->at(i).at(j)));
		}
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("%c", '#');
		printf("%c", '\n');
	}

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (int i = 0; i < size + 2; i++)
		printf("%c", '#');
	printf("%c", '\n');

	printf("%s %d", "\nHealth:", player->getHealth());
	printf("%c", '\n');
	/*printf("%s %d", "\nAvailable Blessings:", player->getGodsBlessing());
	printf("%c", '\n');*/
	printf("\nKeys Found: %d / %d", player->getKeys(), field->getKeysAmount());
	printf("%c", '\n');
}