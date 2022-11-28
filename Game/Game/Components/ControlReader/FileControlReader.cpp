#include "FileControlReader.h"

FileControlReader::FileControlReader()
{
    set_file_output();
	setControl();
}

FileControlReader::~FileControlReader()
{
    free_file();
}
std::string FileControlReader::getTextForEnum(eDirection type)
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
eDirection FileControlReader::read(char key)
{
	for (int i = 0; i < control.size(); i++) {  // выводим их
		if (control.at(i).first == key)
			return control.at(i).second;
	}
	return STOP;
}

std::vector<std::pair<char, eDirection>>* FileControlReader::getControl()
{
	return &control;
}

void FileControlReader::setControl()
{
	bool flag = true;
	std::string command_str;
	char command_key;
	int command_enum;
	while (!file.eof()) {
		file >> command_str >> command_key >> command_enum;
		for (int i = 0; i < control.size(); i++) {  // выводим их
			if (control.at(i).first == command_key) {
				flag = false;
				break;;
			}
		}
		if (flag) {
			std::pair<char, eDirection>temp(command_key, eDirection(command_enum));
			control.push_back(temp);
		}
	}
}

void FileControlReader::free_file()
{
	change_file();
    file.close();
}

void FileControlReader::enable_file_output()
{
	if (file.is_open()) {
		file.close();
	}

	file.open(file_path, std::ios_base::in);
	if (file.fail()) {
		printf("[LOGGER] Failed to open file at %s", file_path);
	}
}

void FileControlReader::set_file_output()
{
	file_path = "Control/Control.txt";
	enable_file_output();
}

void FileControlReader::change_file()
{
	if (file.is_open())
		file.close();
	file.open(file_path, std::ios_base::out);
	if (file.fail())
		printf("[LOGGER] Failed to open file at %s", file_path);
	if (file.is_open()) {
		file.seekp(std::ios::beg);
		for (int i = 0; i < control.size(); i++) {  // выводим их
			file << getTextForEnum(control.at(i).second) << " " << control.at(i).first << " " << i + 1 << "\n";
			if (file.bad()) {
				printf("Error");
				_getch();
			}
			system("CLS");
		}
	}
}

