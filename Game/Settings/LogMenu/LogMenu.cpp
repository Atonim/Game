#include "LogMenu.h"

LogMenu::LogMenu(LogObserver* observer) : observer_(observer) {}

void LogMenu::run()
{
	system("cls");
	printf("Choose an option:\n\n\
	0 - No logging\n\
	1 - Console logging\n\
	2 - File logging\n\
	3 - Console and File logging\n\n\
	Press any other button to skip\n\n");

	char set;
	std::cin >> set;
	switch (set)
	{
	case '0':
		break;
	case '1':
		addConsoleLogger();
		setlevel();
		break;
	case '2':
		addFileLogger();
		setlevel();
		break;
	case '3':
		addConsoleLogger();
		addFileLogger();
		setlevel();
		break;
	default:
		break;
	}


	
}

void LogMenu::setlevel()
{
	system("cls");
	printf("Choose logging level:\n\n\
	0 - Errors Level\n\
	1 - Game Global Info Level\n\
	2 - Event Info Level (default)\n\n\
	Press any other button to skip\n\n");

	char set;
	std::cin >> set;
	switch (set)
	{
	case '0':
		observer_->setPriority(ERRLVL);
		break;
	case '1':
		observer_->setPriority(GAMELVL);
		break;
	case '2':
		observer_->setPriority(INFOLVL);
		break;
	default:
		break;
	}
}

void LogMenu::addConsoleLogger()
{
	observer_->addLogger(new ConsoleLog);
}

void LogMenu::addFileLogger()
{
	observer_->addLogger(new FileLog);
}
