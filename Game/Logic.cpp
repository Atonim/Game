#include "Logic.h"

void Logic::start(int dir, Field& field)
{
	int newX, newY;	//���������� ��� ����� �������� ��������� ������
	switch (dir) {  //��������� ����������� �������� � ������� ������ � ������ �������
	case STOP:
		break;
	case UP:
		newY = field.currentPlayerY() - 1;
		if (newY < 0)
			newY = field.height() - 1;
		if (field.matrix().at(newY).at(field.currentPlayerX())->getType())
			field.movePlayerY(newY);
		break;
	case LEFT:
		newX = field.currentPlayerX() - 1;
		if (newX < 0)
			newX = field.width() - 1;
		if (field.matrix().at(field.currentPlayerY()).at(newX)->getType())
		field.movePlayerX(newX);
		break;
	case DOWN:
		newY = field.currentPlayerY() + 1;
		if (newY > field.height() - 1)
			newY = 0;
		if (field.matrix().at(newY).at(field.currentPlayerX())->getType())
			field.movePlayerY(newY);
		break;
	case RIGHT:
		newX = field.currentPlayerX() + 1;
		if (newX > field.width() - 1)
			newX = 0;
		if (field.matrix().at(field.currentPlayerY()).at(newX)->getType())
			field.movePlayerX(newX);
		break;
	}

	field.matrix().at(field.currentPlayerY()).at(field.currentPlayerX())->playerContact(); //������ ��������� �� ������
	
}
