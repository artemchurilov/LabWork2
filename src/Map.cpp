/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Map.h"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height)
{
    for (int y = 0; y < height; ++y) {
        std::vector<std::shared_ptr<Cell>> row;
        for (int x = 0; x < width; ++x) {
            row.push_back(std::make_shared<Cell>());
        }
        grid.push_back(row);
    }
};     

void Map::render() const {
for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
        std::cout << grid[y][x]->getSymbol() << ' ';
    }
    std::cout << std::endl;
}
}

void Map::setCell(int x, int y, CellType type)
{
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x]->setType(type);
    }
}
