#pragma once
#include "LogLevel.h"
#include "ErrMessage.h"
class ErrLevel : public LogLevel
{
public:
	bool check(logLevel priority) override;
	const char* get_sentence(int key) override;
};
//Уровень ошибок

