#include "Field.h"
Field::Field() : size(10), playerX(0), playerY(0) {
    //std::cout << "CONSTRUCT " << this << "\n";
    for (int i = 0; i < size; i++) {
        mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                mat.back().emplace_back(new Cell(SHRINE));
            }
            else if (!(rand() % 5)) {
                mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                mat.back().emplace_back(new Cell(CHEST));
            }
            else if (!(rand() % 50))
            {
                mat.back().emplace_back(new Cell(TRAP));
            }
            else {
                mat.back().emplace_back(new Cell(SPACE));
            }
        }
    }
};
Field::Field(int size) : size(size), playerX(0), playerY(0) {
    //std::cout << "CONSTRUCT ARG " << this << "\n";
    for (int i = 0; i < size; i++) {
        mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                mat.back().emplace_back(new Cell(SHRINE));
            }
            else if (!(rand() % 5)) {
                mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                mat.back().emplace_back(new Cell(CHEST));
            }
            else if (!(rand() % 50))
            {
                mat.back().emplace_back(new Cell(TRAP));
            }
            else {
                mat.back().emplace_back(new Cell(SPACE));
            }
        }
    }
};
Field::~Field() {
    //std::cout << "DELETE " << this << "\n";
    for (auto row : mat) {
        for (auto elem: row)
            delete elem;
    }
}
Field::Field(const Field& obj)
{
    //std::cout << "COPY " << this << "\n";
    this->size = obj.size;
    this->playerX = obj.playerX;
    this->playerY = obj.playerY;
    for (int i = 0; i < size; i++) {
        mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                mat.back().emplace_back(new Cell(SHRINE));
            }
            else if (!(rand() % 5)) {
                mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                mat.back().emplace_back(new Cell(CHEST));
            }
            else if (!(rand() % 50))
            {
                mat.back().emplace_back(new Cell(TRAP));
            }
            else {
                mat.back().emplace_back(new Cell(SPACE));
            }
        }
    }

}
Field& Field::operator=(const Field& obj)
{
    //std::cout << "OPERATOR COPY " << this << "\n";
    for (auto row : this->mat) {
        for (auto elem : row)
            delete elem;
    }
    this->size = obj.size;
    this->playerX = obj.playerX;
    this->playerY = obj.playerY;
    for (int i = 0; i < size; i++) {
        mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                mat.back().emplace_back(new Cell(SHRINE));
            }
            else if (!(rand() % 5)) {
                mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                mat.back().emplace_back(new Cell(CHEST));
            }
            else if (!(rand() % 50))
            {
                mat.back().emplace_back(new Cell(TRAP));
            }
            else {
                mat.back().emplace_back(new Cell(SPACE));
            }
        }
    }

    return *this;
}
Field::Field(Field&& obj)
{
    //std::cout << "MOVE " << this << "\n";
    std::swap(this->size, obj.size);
    std::swap(this->playerX, obj.playerX);
    std::swap(this->playerY, obj.playerY);
    std::swap(this->mat, obj.mat);
}

Field& Field::operator=(Field&& obj)
{
    //std::cout << "OPERATOR MOVE " << this << "to" << &obj << "\n";
    if (this != &obj) {
        std::swap(this->size, obj.size);
        std::swap(this->playerX, obj.playerX);
        std::swap(this->playerY, obj.playerY);
        std::swap(this->mat, obj.mat);
    }
    return *this;
}

int Field::getSize() {
	return size;
}

std::vector<std::vector<Cell*>> Field::getMatrix()
{
    return mat;
}

int Field::getPlayerX()
{
    return playerX;
}

int Field::getPlayerY()
{
    return playerY;
}

void Field::movePlayerX(int distance)
{
    playerX = distance;
}

void Field::movePlayerY(int distance)
{
    playerY = distance;
}
//
//Player* Field::getPlayer()
//{
//    return &player;
//}
