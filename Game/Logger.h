#pragma once
#include "LogLevel.h"
class Logger
{
protected:
	LogLevel* priority;
public:
	virtual void print(const char* message) = 0;
	void set_priorety(LogLevel* priority);
	void run(const char* message);
};
