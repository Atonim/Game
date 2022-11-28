#include "Menu.h"
void Menu::GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void Menu::ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяем видимость курсора
	structCursorInfo.dwSize = size; // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void Menu::run() {
	
	SetConsoleTitle(L"MINOTAURUS"); //название консоли
	system("CLS");
	ConsoleCursorVisible(false, 100); //убираем курсор

	std::string Menu[] = { "New game", "Load game", "Settings", "Exit" };
	
	//инициализация штук
	
	//наблюдатель для логгера
	LogObserver observer;

	//поле
	Field field;

	//контроллер
	FileControlReader control_reader;
	

	

	
	char ch;
	while (true) {
		int x = 50, y = 12;
		GoToXY(x, y);

		for (int i = 0; i < size(Menu); i++) {
			if (i == active_menu)
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(x, y++);
			std::cout << Menu[i] << "\n";
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
			if (active_menu < size(Menu) - 1) {
				active_menu++;
				PlaySound(TEXT("Music/menu_scroll.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			}
			break;
		case ENTER:
			PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			switch (active_menu)
			{
			case 0:
			{
				Game game;
				game.run(&observer, &field, &control_reader);
				system("CLS");
				break;
			}
			case 1:
			{
				break;
			}
			case 2:
			{
				
				Settings settings;
				settings.run(&observer, &field, &control_reader);
				system("CLS");
				break;
			}
			case 3:
				control_reader.change_file();
				exit(0);
			}
			break;
		}
		
	}
}
