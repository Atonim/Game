#include "LevelMenu.h"

void LevelMenu::drawMenu()
{
	system("CLS");
	int x = 50, y = 12;
	GoToXY(x, y);

	for (int i = 0; i < size(settings_str); i++) {
		if (i == active_menu)
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		else
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		GoToXY(x, y++);
		/*if (i + 1 != size(settings_str)) {
			std::cout << settings_str[i] << " ";
			if (trigger == settings_enum[i]) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			if (input_active && i + 1 == trigger)
				std::cout << ch << "\n";
			else
				std::cout << settings_key[i] << "\n";
		}
		else*/
		std::cout << settings_str[i] << "\n";
	}
}
void LevelMenu::run(LevelContext* context)
{
	ConsoleCursorVisible(false, 100); //убираем курсор

	while (settings_active) {

		drawMenu();
		ch = _getch();

		if (ch == -32)
			ch = _getch(); // отлавливаем стрелочки


		switch (ch)
		{
		case UP:
			if (active_menu > 0) {
				active_menu--;
				PlaySound(TEXT("Music/menu_scroll.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			}
			break;
		case DOWN:
			if (active_menu < size(settings_str) - 1) {
				active_menu++;
				PlaySound(TEXT("Music/menu_scroll.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			}
			break;
		case ENTER: {
			PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			switch (active_menu) {
			case 0: {
				context->setStrategy(new EasyLevel);
				settings_active = false;
				break;
			}
			case 1: {
				context->setStrategy(new MediumLevel);
				settings_active = false;
				break;
			}
			default:
				settings_active = false;
				system("CLS");
				break;
			}
			break;

		}
		}


	}
}
