#pragma once
#include "LogLevel.h"
#include "Mytypes.h"
#include "InfoMessage.h"
class InfoLevel : public LogLevel
{
public:
	bool check(logLevel priority) override;
	const char* get_sentence(int key) override;
};
//уровень состояния событий/клеток/поля - инфа
