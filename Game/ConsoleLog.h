#pragma once
#include "Logger.h"
#include "InfoLevel.h"
#include <iostream>
class ConsoleLog : public Logger
{
public:
	void print(const char* message);
};

