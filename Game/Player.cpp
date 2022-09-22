#include "Player.h"

Player::Player() :health(100), keysFound(0), speed(1)
{
	//std::cout << "PLAYER CONSRRUCT " << this << "\n";
}

Player::~Player()
{
	//std::cout << "PLAYER DELETE " << this << "\n";
}

Player::Player(const Player& obj)
{
	this->health = obj.health;
	this->keysFound = obj.keysFound;
	this->speed = obj.speed;
}

Player& Player::operator=(const Player& obj)
{
	this->health = obj.health;
	this->keysFound = obj.keysFound;
	this->speed = obj.speed;
	return *this;
}

void Player::keysPlus()
{
	keysFound++;
}

void Player::treatment()
{
	health += 25;
}

void Player::getDamage()
{
	health -= 25;
}

void Player::speedUp()
{
	speed++;
}

void Player::speedDown()
{
	if (speed > 1)
	speed--;
}

int Player::currentKeys()
{
	return keysFound;
}

int Player::currentHealth()
{
	return health;
}

int Player::currentSpeed()
{
	return speed;
}
