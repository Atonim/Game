#pragma once
#include <vector>
#include "Player.h"
#include "Cell.h"

class Field
{
	int fieldHeight;
	int fieldWidth;
	std::vector<std::vector<Cell*>> mat;
	Player player;
	int playerX;
	int playerY;
	
public:
	Field(); //���������� 
	Field(Player&, int, int); //����������� � ����������� �����������
	~Field(); //����������
	Field(const Field&); //����������� �����������
	Field& operator =(const Field&);
	Field(Field&&);
	Field& operator=(Field&& obj);
	int height();
	int width();
	std::vector<std::vector<Cell*>> matrix();
	int currentPlayerX();
	int currentPlayerY();
	void movePlayerX(int);
	void movePlayerY(int);
	Player& getPlayer();
};

