#include "Player.h"

Player::Player() : health(100), keysFound(0), godsBlessing(3)
{
	//std::cout << "PLAYER CONSRRUCT " << this << "\n";
}

Player::~Player()
{
	//std::cout << "PLAYER DELETE " << this << "\n";
}

//Player::Player(const Player& obj)
//{
//	//std::cout << "PLAYER COPY " << this << "\n";
//	
//}
//
//Player::Player(Player&&)
//{
//	//std::cout << "PLAYER MOVE " << this << "\n";
//}
//
//Player& Player::operator=(const Player& obj)
//{
//	//std::cout << "PLAYER COPY OP " << this << "\n";
//	return *this;
//}
//
//Player& Player::operator=(Player&&)
//{
//	//std::cout << "PLAYER MOVE OP " << this << "\n";
//	return *this;
//}

void Player::keysPlus()
{
	keysFound++;
}

void Player::treatment()
{
	health += 5;
}

void Player::damage()
{
	health -= 5;
}

void Player::blessing()
{
	godsBlessing--;
}

int Player::getKeys()
{
	return keysFound;
}

int Player::getHealth()
{
	return health;
}

int Player::getGodsBlessing() {
	return godsBlessing;
}
