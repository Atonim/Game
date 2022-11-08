#pragma once
#include "Logger.h"
#include "LogLevels/InfoLevel.h" //õç
#include <iostream>
class ConsoleLog : public Logger
{
public:
	void print(const char*) override;
};

