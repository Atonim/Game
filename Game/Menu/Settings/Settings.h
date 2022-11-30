#pragma once
#include "../../Game/Components/Logger/LogObserver/LogObserver.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "../Settings/LogMenu/LogMenu.h"
#include "FieldMenu/FieldSettings.h"
#include "ControlMenu/ControlMenu.h"
#include "../../Game/Components/ControlReader/IControlReader.h"
#include "../Menu.h"
#include "../../Game/Components/LevelContext/LevelContext.h"
class Settings : public Menu
{
	enum KEYS { ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
	int active_menu = 0;
public:
	void run(LogObserver*, LevelContext*, IControlReader*);
};

