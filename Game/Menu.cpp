#include "Menu.h"
void Menu::start(Field& field) {
	char set;
	std::cout << "Press '1' to set map size\nPress any button to continue with default map (10x10)\n";
	std::cin >> set;
	switch (set)
	{
	case '1':
		int size;
		std::cout << "Map size: ";
		std::cin >> size;
		field = Field(size);
		break;
	}
	std::cout << "\n'W' - Up\n'A' - Left\n'S' - Down\n'D' - Right\n'G' - Pray to the Gods\n'X' - Exit\n\nPress any button to start\n";
	std::cin >> set;
}