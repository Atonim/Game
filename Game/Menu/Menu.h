#pragma once
#include <Windows.h>
class Menu
{
protected:
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int active_menu = 0;
public:
	void GoToXY(short x, short y);
	void ConsoleCursorVisible(bool show, short size);
};

