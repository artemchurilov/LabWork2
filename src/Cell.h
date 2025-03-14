/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CELL_H
#define CELL_H

enum class CellType {
    EMPTY,
    WALL,
    PLAYER
};

class Cell {
public:
    Cell(CellType type = CellType::EMPTY);
    void setType(CellType newType);
    char getSymbol() const;

private:
    CellType type;
};

#endif