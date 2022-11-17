#include "ControlMenu.h"
void ControlMenu::GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void ControlMenu::ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяем видимость курсора
	structCursorInfo.dwSize = size; // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void ControlMenu::change_file()
{
	if (file.is_open()) {
		file.close();
	}

	file.open(file_path, std::ios_base::out);
	if (file.fail()) {
		printf("[LOGGER] Failed to open file at %s", file_path);
	}
	if (file.is_open()) {
		file.seekp(std::ios::beg);
		for (int i = 0; i < size(settings_key); i++)
			file << settings_str[i] << " " << settings_key[i] << " " << i+1 << "\n";
		if (file.bad())
			printf("Error");
		else
			printf("Settings have been updated!");
		_getch();
		system("CLS");
	}
	
	
}
void ControlMenu::drawMenu()
{
	system("CLS");
	int x = 50, y = 10;
	GoToXY(x, y);

	for (int i = 0; i < size(settings_str); i++) {
		if (i == active_menu)
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		else
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		GoToXY(x, y++);
		if (i + 1 != size(settings_str)) {
			std::cout << settings_str[i] << " ";
			if (trigger == settings_enum[i]) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			if (input_active && i+1 == trigger)
				std::cout << ch << "\n";
			else
				std::cout << settings_key[i] << "\n";
		}
		else
			std::cout << settings_str[i] << "\n";
	}
}
ControlMenu::ControlMenu()
{
	set_file_output();
}
ControlMenu::~ControlMenu()
{
	change_file();
	free_file();
}
void ControlMenu::free_file()
{
	file.close();
}
void ControlMenu::enable_file_output()
{
	if (file.is_open()) {
		file.close();
	}

	file.open(file_path, std::ios_base::in | std::ios_base::out);
	if (file.fail()) {
		printf("[LOGGER] Failed to open file at %s", file_path);
	}
}
void ControlMenu::set_file_output()
{
	file_path = "Control/Control.txt";
	enable_file_output();
}
void ControlMenu::run()
{
	
	ConsoleCursorVisible(false, 100); //убираем курсор
	
	
	std::string command_str;
	char command_key;
	int command_enum;
	while (!file.eof()) {
		file >> command_str >> command_key >> command_enum;
		if (std::find(settings_str.begin(), settings_str.end(), command_str) == settings_str.end()) {
			settings_str.push_back(command_str);
			settings_key.push_back(command_key);
			settings_enum.push_back(command_enum);
		}
	}
	settings_str.push_back("<- Back");


	
	while (settings_active) {
		
		drawMenu();
		ch = _getch();
		
		if (ch == -32)
			ch = _getch(); // отлавливаем стрелочки
		
		if (!trigger) {
			switch (ch)
			{
			case UP:
				if (active_menu > 0) {
					active_menu--;
					PlaySound(TEXT("Music/menu_scroll.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				}
				break;
			case DOWN:
				if (active_menu < size(settings_str) - 1) {
					active_menu++;
					PlaySound(TEXT("Music/menu_scroll.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				}
				break;
			case ENTER:
				PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				if (active_menu != size(settings_str) - 1) {
					trigger = active_menu + 1;
				}
				else {
					settings_active = false;
					system("CLS");
					break;
				}
				break;
			}
		}
		else {
			input_active = true;
			while (input_active) {
				drawMenu();
				new_ch = _getch();
				if (new_ch == -32)
					new_ch = _getch(); // отлавливаем стрелочки
				
				switch (new_ch)
				{
				case ENTER:
					PlaySound(TEXT("Music/menu_enter.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
					if (std::find(settings_key.begin(), settings_key.end(), (char)toupper(ch)) != settings_key.end()) {
						printf("[LOGGER] This key is already taken");
						_getch();
						continue;
					}
					else {
						settings_key.at(trigger - 1) = (char)toupper(ch);
						input_active = false;
						trigger = 0;
						system("CLS");
						break;
					}
				}
				ch = new_ch;
			}
		}
		

	}
}
