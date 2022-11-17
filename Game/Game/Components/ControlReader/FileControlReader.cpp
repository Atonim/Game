#include "FileControlReader.h"

FileControlReader::FileControlReader()
{
    set_file_output();
}

FileControlReader::~FileControlReader()
{
    free_file();
}

eDirection FileControlReader::read(char key)
{
	file.seekp(std::ios::beg);
	std::string command_str;
	char command_key;
	int command_enum;
	while (!file.eof()) {
		file >> command_str >> command_key >> command_enum;
		if (command_key == (char)toupper(key)) {
			return eDirection(command_enum);
		}
	}
    return STOP;
}

void FileControlReader::free_file()
{
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
