#pragma once
#include "windows.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <map>
#include "../../../Game/Components/ControlReader/IControlReader.h"
#include "../../Menu.h"
class ControlMenu : public Menu
{
	char ch, new_ch;
	int trigger = 0; //проверка на то был ли прожат enter
	bool input_active = false;
	bool settings_active = true;
	std::vector<std::pair<char, eDirection>>* control;
	std::vector<std::string>settings_str;
	std::vector<char>settings_key;
	std::vector<int>settings_enum;
	enum KEYS { ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
public:
	ControlMenu(std::vector<std::pair<char, eDirection>>*);
	~ControlMenu();
	void run();
	void update();
	std::string getTextForEnum(eDirection);
	void read();
	void drawMenu();
};

