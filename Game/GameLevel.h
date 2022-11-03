#pragma once
#include "LogLevel.h"
#include "GameMessage.h"
class GameLevel : public LogLevel
{
public:
	bool check(logLevel priority) override;
	const char* get_sentence(int key) override;
};
//Уровень состояния игры
