#pragma once
#include <vector>
#include <utility>
#include "../Player/Player.h"
#include "Cell/Cell.h"

class Field
{
	int size;	//размер поля

	std::vector<std::vector<Cell*>> mat;		//матрица клеток

	int trapsAmount;
	int keysAmount;
	int wallsAmount;

	std::pair<int, int> playerXY; //координаты игрока
	
public:
	//конструкторы
	Field(); //коструктор 
	~Field(); //деструктор
	Field(const Field&); //конструктор копирования
	Field& operator =(const Field&);
	Field(Field&&);
	Field& operator=(Field&& obj);

	//сеттеры
	void setSize(int);
	void setHeroSpawn(int, int);

	void setTrapsAmount(int);
	void setKeysAmount(int);
	void setWallsAmount(int);

	//геттеры
	int getSize();
	std::vector<std::vector<Cell*>>* getMatrix();
	
	std::pair<int, int> getPlayerXY();

	int getTrapsAmount();
	int getWallsAmount();
	int getKeysAmount();

	//изменение координаты игрока
	void movePlayerXY(int, int);
};

