#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "IControlReader.h"
class FileControlReader : public IControlReader
{
	const char* file_path = 0;
	std::fstream file;
public:
	FileControlReader();
	~FileControlReader();
	eDirection read(char);
	void free_file();
	void enable_file_output();
	void set_file_output();
};

