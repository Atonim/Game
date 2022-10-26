#include "Menu.h"
void Menu::start(Field& field) {
	system("cls");
	char set;
	std::cout << "- Press '1' to set map size (Size must be 10-15)\n- Press any button to continue with default map (10x10)\n";
	std::cin >> set;
	switch (set)
	{
	case '1':
		int size = 0;
		while (true) {
			system("cls");
			std::cout << "Map size: ";
			std::cin >> size;
			if (std::cin.fail()) {					// извлечение не производилось
				// сбрасываем биты состояния обратно в goodbit,
				// чтобы мы могли использовать ignore()
				std::cin.clear();					// очищаем недопустимый ввод из потока
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				// попробовать снова
				notify(new ErrMessage, FIELD);		//логируем ошибку
				getchar();
				continue;
			}
			// очищаем любой дополнительный ввод из потока
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)				// если мы удалили более одного дополнительного символа
			{
				notify(new ErrMessage, FIELD);
				getchar();
				continue;							// будем считать этот ввод недопустимым
			}

			if (size < 10 || size > 15)				// убедиться, что значение какое нужно
			{
				notify(new ErrMessage, FIELD);
				getchar();
				continue;
			}

			break;
		}
		field = Field(size);
		break;
	}
	system("cls");
	std::cout << "'W' - Up\n'A' - Left\n'S' - Down\n'D' - Right\n'G' - Pray to the Gods\n'X' - Exit\n\nPress any button to start\n";
	getchar();
}

void Menu::attach(ILogObserver* observer)
{
	list_observer_.push_back(observer);
}

void Menu::detach(ILogObserver* observer)
{
	list_observer_.remove(observer);
}

void Menu::notify(IMessage* messagelvl, int key)
{
	std::list<ILogObserver*>::iterator iterator = list_observer_.begin();
	while (iterator != list_observer_.end()) {
		//тут вызываем методы обсервера 
		const char* message = messagelvl->get_message(key);
		(*iterator)->update(message);
		++iterator;
	}
}
