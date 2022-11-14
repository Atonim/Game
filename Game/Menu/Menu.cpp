#include "Menu.h"
void Menu::GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void Menu::ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // �������� ��������� �������
	structCursorInfo.dwSize = size; // �������� ������ �������
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void Menu::run() {
	SetConsoleTitle(L"MINOTAURUS"); //�������� �������
	system("CLS");
	ConsoleCursorVisible(false, 100); //������� ������

	std::string Menu[] = { "New game", "Load game", "Settings", "Exit" };
	
	//������������� ����
	
	//����������� ��� �������
	LogObserver observer;

	//����
	Field field;


	

	

	
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
			ch = _getch(); // ����������� ���������
		
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
			switch (active_menu)
			{
			case 0:
			{
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				Game game;
				game.run(&observer, &field);
				system("CLS");
				break;
			}
			case 1:
			{
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				break;
			}
			case 2:
			{
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				Settings settings;
				settings.run(&observer, &field);
				system("CLS");
				break;
			}
			case 3:
				exit(0);
			}
			break;
		}
		
	}
	_getch();
}
