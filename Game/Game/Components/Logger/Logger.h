#pragma once
#include "LogLevels/LogLevel.h"
#include "LogLevels/ErrLevel.h"
#include <iostream>
class Logger
{
public:
	virtual void print(const char*) = 0;
	//void run(const char* message);
};
