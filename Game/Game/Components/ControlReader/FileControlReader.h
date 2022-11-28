#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "IControlReader.h"
#include <utility>
#include <conio.h>
#include <vector>
class FileControlReader : public IControlReader
{
	std::vector<std::pair<char, eDirection>> control;
	const char* file_path = 0;
	std::fstream file;
public:
	FileControlReader();
	~FileControlReader();
	eDirection read(char);
	std::vector<std::pair<char, eDirection>>* getControl();
	std::string getTextForEnum(eDirection);
	void setControl();
	void free_file();
	void enable_file_output();
	void set_file_output();
	void change_file();
};

