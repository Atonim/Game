#include "Menu.h"
void Menu::start(Field& field, Player& player) {
	char set;
	std::cout << "Press '1' to set map size\nPress any button to continue with default map (10x10)\n";
	std::cin >> set;
	switch (set)
	{
	case '1':
		int height, width;
		std::cout << "Width: ";
		std::cin >> width;
		std::cout << "Height: ";
		std::cin >> height;
		field = Field(player, height, width);
		break;
	}
	std::cout << "\n'W' - Up\n'A' - Left\n'S' - Down\n'D' - Right\n'G' - Pray to the Gods\n'X' - Exit\n\nPress any button to start\n";
	std::cin >> set;
}