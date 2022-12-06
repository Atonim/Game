#include "Field.h"
Field::Field() {
    //std::cout << "CONSTRUCT " << this << "\n";
    this->size = 20;
    for (int i = 0; i < size; i++) {
        mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < size; j++)
            mat.back().emplace_back(new Cell(SPACE));
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
    this->playerXY = obj.playerXY;
    this->keysAmount = obj.keysAmount;
    this->mat = obj.mat;
    this->trapsAmount = obj.trapsAmount;
    this->wallsAmount = obj.wallsAmount;

}
Field& Field::operator=(const Field& obj)
{
    //std::cout << "OPERATOR COPY " << this << "\n";
    for (auto row : this->mat) {
        for (auto elem : row)
            delete elem;
    }
    this->size = obj.size;
    this->playerXY = obj.playerXY;
    this->keysAmount = obj.keysAmount;
    this->mat = obj.mat;
    this->trapsAmount = obj.trapsAmount;
    this->wallsAmount = obj.wallsAmount;
    

    return *this;
}
Field::Field(Field&& obj)
{
    //std::cout << "MOVE " << this << "\n";
    std::swap(this->size, obj.size);
    std::swap(this->playerXY, obj.playerXY);
    std::swap(this->mat, obj.mat);
    std::swap(this->keysAmount, obj.keysAmount);
    std::swap(this->trapsAmount, obj.trapsAmount);
    std::swap(this->wallsAmount, obj.wallsAmount);
}

Field& Field::operator=(Field&& obj)
{
    //std::cout << "OPERATOR MOVE " << this << "to" << &obj << "\n";
    if (this != &obj) {
        for (auto row : this->mat) {
            for (auto elem : row)
                delete elem;
        }
        std::swap(this->size, obj.size);
        std::swap(this->playerXY, obj.playerXY);
        std::swap(this->mat, obj.mat);
        std::swap(this->keysAmount, obj.keysAmount);
        std::swap(this->trapsAmount, obj.trapsAmount);
        std::swap(this->wallsAmount, obj.wallsAmount);
    }
    return *this;
}

int Field::getSize() {
	return size;
}

void Field::setSize(int size)
{
    this->size = size;
}

void Field::setHeroSpawn(int X, int Y)
{
    this->playerXY.first = X;
    this->playerXY.second = Y;
}

std::vector<std::vector<Cell*>>* Field::getMatrix()
{
    return &mat;
}

int Field::getTrapsAmount()
{
    return this->trapsAmount;
}

int Field::getWallsAmount()
{
    return this->wallsAmount;
}

int Field::getKeysAmount()
{
    return this->keysAmount;
}

std::pair<int, int> Field::getPlayerXY()
{
    return this->playerXY;
}

void Field::movePlayerXY(int X, int Y)
{
    this->playerXY.first = X;
    this->playerXY.second = Y;
}

void Field::setTrapsAmount(int amount)
{
    this->trapsAmount = amount;
}

void Field::setKeysAmount(int amount)
{
    this->keysAmount = amount;
}

void Field::setWallsAmount(int amount)
{
    this->wallsAmount = amount;
}
