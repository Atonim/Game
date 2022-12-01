#pragma once
#include "../../Menu.h"
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include "../../../Game/Components/LevelContext/LevelContext.h"
#include "../../../Game/Components/StrategyLevel/EasyLevel/EasyLevel.h"
#include "../../../Game/Components/StrategyLevel/MediumLevel/MediumLevel.h"
class LevelMenu : public Menu
{
	char ch;
	bool settings_active = true;
	std::vector<std::string>settings_str {"Easy", "Medium", "<- Back"};
	enum KEYS { ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
public:
	void run(LevelContext* context);
	void drawMenu();
};

