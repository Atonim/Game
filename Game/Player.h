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
	Player& operator=(const Player&);*/
	void keysPlus();
	void treatment();
	void getDamage();
	void blessing();
	int getKeys();
	int getHealth();
	int getGodsBlessing();
};

