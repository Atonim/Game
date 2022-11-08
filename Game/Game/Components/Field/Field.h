#pragma once
#include <vector>
#include "../Player/Player.h"
#include "Cell/Cell.h"

class Field
{
	int size;
	std::vector<std::vector<Cell*>> mat;
	std::vector<Cell*> traps;
	std::vector<Cell*> keys;
	std::vector<Cell*> walls;
	int playerX;
	int playerY;
	
public:
	Field(); //коструктор 
	Field(int); //конструктор с переданными параметрами
	~Field(); //деструктор
	Field(const Field&); //конструктор копирования
	Field& operator =(const Field&);
	Field(Field&&);
	Field& operator=(Field&& obj);
	int getSize();;
	std::vector<std::vector<Cell*>> getMatrix();
	int getKeys();
	int getTraps();
	int getWalls();
	int getPlayerX();
	int getPlayerY();
	void movePlayerX(int);
	void movePlayerY(int);
	//Player* getPlayer();
};

