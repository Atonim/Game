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