#pragma once
#include "windows.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
class ControlMenu
{
	char ch, new_ch;
	int trigger = 0; //проверка на то был ли прожат enter
	bool input_active = false;
	bool settings_active = true;
	std::vector<std::string>settings_str;
	std::vector<char>settings_key;
	std::vector<int>settings_enum;
	const char* file_path = 0;
	std::fstream file;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	enum KEYS { ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
	int active_menu = 0;
public:
	ControlMenu();
	~ControlMenu();
	void free_file();
	void enable_file_output();
	void set_file_output();
	void run();
	void GoToXY(short x, short y);
	void ConsoleCursorVisible(bool show, short size);
	void change_file();
	void drawMenu();
};

