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
std::string ControlMenu::getTextForEnum(eDirection type)
{
	switch (type) {
	case eDirection::UP:
		return "UP";
	case eDirection::LEFT:
		return "LEFT";
	case eDirection::RIGHT:
		return "RIGHT";
	case eDirection::DOWN:
		return "DOWN";
	case eDirection::ABILITY:
		return "ABILITY";
	case eDirection::EXIT:
		return "EXIT";
	default:
		return "STOP";
	}
}
void ControlMenu::update()
{
	for (int i = 0; i < settings_key.size(); i++) {
		control->at(i).first = settings_key[i];
	}
		//control->at(settings_key[i]) = eDirection(settings_enum[i]);
	
}
void ControlMenu::read()
{
	std::string command_str;
	char command_key;
	int command_enum;
	for (int i = 0; i < control->size(); i++) {  // выводим их
		/*std::cout << control->at(i).first << " " << control->at(i).second << std::endl;*/
		settings_str.push_back(getTextForEnum(control->at(i).second));
		settings_key.push_back(control->at(i).first);
		settings_enum.push_back(control->at(i).second);
	}
	settings_str.push_back("<- Back");
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
ControlMenu::ControlMenu(std::vector<std::pair<char, eDirection>>* control)
{
	this->control = control;
}
ControlMenu::~ControlMenu()
{
	update();
}
//void ControlMenu::free_file()
//{
//	file.close();
//	control_reader->update(control);
//}
//void ControlMenu::enable_file_output()
//{
//	if (file.is_open()) {
//		file.close();
//	}
//
//	file.open(file_path, std::ios_base::in | std::ios_base::out);
//	if (file.fail()) {
//		printf("[LOGGER] Failed to open file at %s", file_path);
//	}
//}
//void ControlMenu::set_file_output()
//{
//	file_path = "Control/Control.txt";
//	enable_file_output();
//}
void ControlMenu::run()
{
	
	ConsoleCursorVisible(false, 100); //убираем курсор

	read();
	
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
