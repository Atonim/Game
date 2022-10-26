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
	observer_->addLogLvl(new ErrLevel);
	observer_->addLogLvl(new GameLevel);
	observer_->addLogLvl(new InfoLevel);
	/*system("cls");
	printf("\t- Choose an option:\n\n\
	\t0 - No logging\n\
	\t1 - Console logging\n\
	\t2 - File logging\n\
	\t3 - Console and File logging\n\n\
	\tPress any other button to skip\n\n");

	char set;
	std::cin >> set;
	switch (set)
	{
	case '0':

	case '1':
		addConsoleLogger();
		setlevel();
		break;
	case '2':
	case '3':
	default:
		break;
	}*/
}

void LogMenu::addConsoleLogger()
{
	observer_->addLogger(new ConsoleLog);
}

void LogMenu::addFileLogger()
{
	observer_->addLogger(new FileLog);
}
