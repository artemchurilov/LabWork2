/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Map.h"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<Cell>(width));
    
    // Добавляем стены
    grid[1][1].setTerrain(TerrainType::WALL);
    grid[2][2].setTerrain(TerrainType::WALL);
    grid[3][3].setTerrain(TerrainType::WALL);
}


void Map::placeObject(int x, int y, std::shared_ptr<GameObject> obj)
{
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x].setObject(obj);
        }
   
};

void Map::render() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell.getSymbol() << ' ';
        }
        std::cout << '\n';
    }
}