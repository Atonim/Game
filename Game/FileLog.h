#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Logger.h"
#include <fstream>
#include <ostream>
#include <iostream>
class FileLog : public Logger
{
	bool file_output = false;
	const char* file_path = 0;
	FILE* file = 0;
public:
	FileLog();
	FileLog(const char*);
	void free_file();
	void print(const char*);
	~FileLog();
	void enable_file_output();
	void set_file_output(const char*);
	void set_file_output();
};

