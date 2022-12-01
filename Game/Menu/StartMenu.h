#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "../Game/Components/Window/Window.h"
#include "../Game/Game.h"
#include "Settings/Settings.h"
#include "Menu.h"
#include "../Game/Components/Logger/LogObserver/LogObserver.h"
#include "../Game/Components/ControlReader/FileControlReader.h"
#include "../Game/Components/LevelContext/LevelContext.h"
#include "../Game/Components/StrategyLevel/EasyLevel/EasyLevel.h"
class StartMenu : public Window, public Menu
{
	enum KEYS { ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
public:
	void run() override;
};

