#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Logger.h"
#include <fstream>
#include <iostream>
class FileLog : public Logger
{
	const char* file_path = 0;
	std::fstream file;
public:
	FileLog();
	FileLog(const char*);
	void free_file();
	void print(const char*) override;
	~FileLog();
	void enable_file_output();
	void set_file_output(const char*);
	void set_file_output();
	friend std::ostream& operator<<(std::fstream& stream, const char* str);
};

