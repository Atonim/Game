#pragma once
#include <iostream>
class Player
{
	int keysFound;
	int health;
	int godsBlessing;
public:
	Player();
	~Player();
	/*Player(const Player&);
	Player(Player&&);
	Player& operator=(const Player&);
	Player& operator=(Player&&);*/
	void keysPlus();
	void treatment();
	void damage();
	void blessing();
	int getKeys();
	int getHealth();
	int getGodsBlessing();
};

