#pragma once
#include <iostream>
#include "../../Logger/LogObserver/LogObserver.h"
#include "../Window.h"
#include "../../Logger/FileLog.h"
#include "../../Logger/ConsoleLog.h"
#include "../../Logger/LogLevels/ErrLevel.h"
#include "../../Logger/LogLevels/GameLevel.h"
#include "../../Logger/LogLevels/InfoLevel.h"
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

