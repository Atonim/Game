#pragma once
#include <vector>
#include "Player.h"
#include "Cell.h"

class Field
{
	int size;
	std::vector<std::vector<Cell*>> mat;
	int playerX;
	int playerY;
	
public:
	Field(); //���������� 
	Field(int); //����������� � ����������� �����������
	~Field(); //����������
	Field(const Field&); //����������� �����������
	Field& operator =(const Field&);
	Field(Field&&);
	Field& operator=(Field&& obj);
	int getSize();;
	std::vector<std::vector<Cell*>> getMatrix();
	int getPlayerX();
	int getPlayerY();
	void movePlayerX(int);
	void movePlayerY(int);
	//Player* getPlayer();
};

