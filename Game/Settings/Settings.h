#pragma once
#include "../Game/Components/Logger/LogObserver/LogObserver.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "../Settings/LogMenu/LogMenu.h"
#include "FieldMenu/FieldSettings.h"
#include "ControlMenu/ControlMenu.h"
#include "../Game/Components/Field/Field.h"
#include "../Game/Components/ControlReader/IControlReader.h"
class Settings
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	enum KEYS { ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
	int active_menu = 0;
public:
	void run(LogObserver*, Field*, IControlReader*);
	void GoToXY(short x, short y);
	void ConsoleCursorVisible(bool show, short size);
};

