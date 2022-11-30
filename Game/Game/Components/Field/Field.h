#pragma once
#include <vector>
#include <utility>
#include "../Player/Player.h"
#include "Cell/Cell.h"

class Field
{
	int size;	//������ ����

	std::vector<std::vector<Cell*>> mat;		//������� ������

	int trapsAmount;
	int keysAmount;
	int wallsAmount;

	std::pair<int, int> playerXY; //���������� ������
	
public:
	//������������
	Field(); //���������� 
	~Field(); //����������
	Field(const Field&); //����������� �����������
	Field& operator =(const Field&);
	Field(Field&&);
	Field& operator=(Field&& obj);

	//�������
	void setSize(int);
	void setHeroSpawn(int, int);

	void setTrapsAmount(int);
	void setKeysAmount(int);
	void setWallsAmount(int);

	//�������
	int getSize();
	std::vector<std::vector<Cell*>>* getMatrix();
	
	std::pair<int, int> getPlayerXY();

	int getTrapsAmount();
	int getWallsAmount();
	int getKeysAmount();

	//��������� ���������� ������
	void movePlayerXY(int, int);
};

