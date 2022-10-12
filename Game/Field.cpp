#include "Field.h"
Field::Field() : fieldHeight(10), fieldWidth(10), playerX(0), playerY(0), player(player) {
    //std::cout << "CONSTRUCT " << this << "\n";
    for (int i = 0; i < fieldHeight; i++) {
        mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < fieldWidth; j++) {
            if (!(rand() % 5)) {
                mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                mat.back().emplace_back(new Cell(CHEST));
            }
            else {
                mat.back().emplace_back(new Cell(SPACE));
            }
        }
    }
};
Field::Field(Player& player, int height, int width) : Field::Field() {
    //std::cout << "CONSTRUCT ARG " << this << "\n";
    this->fieldHeight = height;
    this->fieldWidth = width;
    this->player = player;
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
    this->player = obj.player;
    this->fieldHeight = obj.fieldHeight;
    this->fieldWidth = obj.fieldWidth;
    this->playerX = obj.playerX;
    this->playerY = obj.playerY;
    this->player = obj.player;
    for (int i = 0; i < fieldHeight; i++) {
        this->mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < fieldWidth; j++) {
            if (!(rand() % 5)) {
                this->mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                this->mat.back().emplace_back(new Cell(CHEST));
            }
            else {
                this->mat.back().emplace_back(new Cell(SPACE));
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
    this->player = obj.player;
    this->fieldHeight = obj.fieldHeight;
    this->fieldWidth = obj.fieldWidth;
    this->playerX = obj.playerX;
    this->playerY = obj.playerY;
    this->player = obj.player;
    for (int i = 0; i < fieldHeight; i++) {
        this->mat.emplace_back(std::vector<Cell*>());
        for (int j = 0; j < fieldWidth; j++) {
            if (!(rand() % 5)) {
                this->mat.back().emplace_back(new Cell(WALL));
            }
            else if (!(rand() % 10))
            {
                this->mat.back().emplace_back(new Cell(CHEST));
            }
            else {
                this->mat.back().emplace_back(new Cell(SPACE));
            }
        }
    }

    return *this;
}
Field::Field(Field&& obj)
{
    //std::cout << "MOVE " << this << "\n";
    std::swap(this->player, obj.player);
    std::swap(this->fieldHeight, obj.fieldHeight);
    std::swap(this->fieldWidth, obj.fieldWidth);
    std::swap(this->playerX, obj.playerX);
    std::swap(this->playerY, obj.playerY);
    std::swap(this->player, obj.player);
    std::swap(this->mat, obj.mat);
}

Field& Field::operator=(Field&& obj)
{
    //std::cout << "OPERATOR MOVE " << this << "to" << &obj << "\n";
    if (this != &obj) {
        std::swap(this->player, obj.player);
        std::swap(this->fieldHeight, obj.fieldHeight);
        std::swap(this->fieldWidth, obj.fieldWidth);
        std::swap(this->playerX, obj.playerX);
        std::swap(this->playerY, obj.playerY);
        std::swap(this->player, obj.player);
        std::swap(this->mat, obj.mat);
    }
    return *this;
}

int Field::height() {
	return fieldHeight;
}
int Field::width() {
	return fieldWidth;
}

std::vector<std::vector<Cell*>> Field::matrix()
{
    return mat;
}

int Field::currentPlayerX()
{
    return playerX;
}

int Field::currentPlayerY()
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

Player* Field::getPlayer()
{
    return &player;
}
