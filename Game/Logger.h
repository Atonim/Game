#pragma once
#include "LogLevel.h"
#include "ErrLevel.h"
#include <iostream>
class Logger
{
public:
	virtual void print(const char*) = 0;
	//void run(const char* message);
};
