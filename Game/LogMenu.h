#pragma once
#include <iostream>
#include "LogObserver.h"
#include "Window.h"
#include "FileLog.h"
#include "ConsoleLog.h"
#include "ErrLevel.h"
#include "GameLevel.h"
#include "InfoLevel.h"
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

