/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <iostream>
#include <memory>
#include <vector>
#include "Map.h"
#include "Cell.h"
#include "../include/const.h"

int main() {
    Map map(MAP_WIDTH, MAP_HEIGHT);
    map.setCell(1, 1, CellType::WALL);
    map.setCell(2, 2, CellType::WALL);
    map.setCell(3, 3, CellType::WALL);
    map.setCell(0, 0, CellType::PLAYER);

    // Рендерим карту
    map.render();

    return 0;
}