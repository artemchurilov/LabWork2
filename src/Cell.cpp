/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Cell.h"

char Cell::getSymbol() const
{
    switch (type) {
        case CellType::EMPTY: return ' ';
        case CellType::WALL: return '#';
        case CellType::PLAYER: return 'P';
        default: return '?';
    }
}

Cell::Cell(CellType type): type(type) {}

void Cell::setType(CellType newType)
{
    type = newType;
}
