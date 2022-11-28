#pragma once
#include <iostream>
#include "../../../Game/Components/Logger/LogObserver/LogObserver.h"
#include "../../../Game/Components/Window/Window.h"
#include "../../../Game/Components/Logger/FileLog.h"
#include "../../../Game/Components/Logger/ConsoleLog.h"
#include "../../../Game/Components/Logger/LogLevels/ErrLevel.h"
#include "../../../Game/Components/Logger/LogLevels/GameLevel.h"
#include "../../../Game/Components/Logger/LogLevels/InfoLevel.h"
class LogMenu : public Window
{
	LogObserver* observer_;
public:
	LogMenu(LogObserver*);
	void run() override;
	void setlevel();
	void addConsoleLogger();
	void addFileLogger();
	/*void removeConsoleLogger();
	void removeFileLogger();*/
};

