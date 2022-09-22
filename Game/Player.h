#pragma once
#include <iostream>
class Player
{
	int keysFound;
	int health;
	int speed;
public:
	Player();
	~Player();
	Player(const Player&);
	Player& operator=(const Player&);
	void keysPlus();
	void treatment();
	void getDamage();
	void speedUp();
	void speedDown();
	int currentKeys();
	int currentHealth();
	int currentSpeed();
};

