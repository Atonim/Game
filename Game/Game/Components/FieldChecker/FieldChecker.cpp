#include "FieldChecker.h"

bool FieldChecker::check(Field* field)
{
    std::pair<int, int> playerXY = field->getPlayerXY();
    int fieldSize = field->getSize();
    std::vector<std::vector<Cell*>>* matrix = field->getMatrix();
    if (playerXY.first > fieldSize || playerXY.second > fieldSize || matrix->at(playerXY.second).at(playerXY.first)->getType() != SPACE || !field->getKeysAmount()) {
        system("cls");
        printf("[ERROR] Impossible level generation process");
        _getch();
        return false;
    }
    return true;

}
