#pragma once
#include "LogLevel.h"
#include "../Messages/InfoMessage.h"
class InfoLevel : public LogLevel
{
public:
	bool check(logLevel priority) override;
	const char* get_sentence(int key) override;
};
//уровень состояния событий/клеток/поля - инфа
