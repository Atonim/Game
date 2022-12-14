#include "Settings.h"

void Settings::run(LogObserver* observer, LevelContext* context, IControlReader* control_reader)
{
	system("CLS");
	ConsoleCursorVisible(false, 100); //убираем курсор
	bool settings_active = true;

	std::string settings[] = { "Level", "Logging", "Control", "<- Back" };
	char ch;
	while (settings_active) {
		int x = 50, y = 12;
		GoToXY(x, y);

		for (int i = 0; i < size(settings); i++) {
			if (i == active_menu)
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(x, y++);
			std::cout << settings[i] << "\n";
		}
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
			if (active_menu < size(settings) - 1) {
				active_menu++;
				PlaySound(TEXT("Music/menu_scroll.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			}
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0: {
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				LevelMenu levelMenu;
				levelMenu.run(context);
				system("CLS");
				break;
			}
			case 1:
			{
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				//настройка логирования
				LogMenu logMenu(observer);
				logMenu.run();
				system("CLS");
				break;
			}
			case 2:
			{
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				ControlMenu controlMenu(control_reader->getControl());
				controlMenu.run();
				system("CLS");
				break;
			}
			case 3:
			{
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				settings_active = false;
				system("CLS");
				break;
			}
			}
			break;
		}

	}
}
