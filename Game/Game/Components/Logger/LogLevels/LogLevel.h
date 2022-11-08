#pragma once
#include "../../../Mytypes.h"
class LogLevel
{
public:
	virtual bool check(logLevel) = 0;
	virtual const char* get_sentence(int) = 0;
};

