/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "GameMap.h"
#include "Inventory.h"
#include <iostream>
#include "StaticObj.h"
#include <cstdlib>

GameMap::GameMap(int w, int h) : width(w), height(h)
{
    grid.resize(h, std::vector<Cell>(w));
    initMap();
}

bool GameMap::movePlayer(int dx, int dy)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (isValidPosition(newX, newY))
    {
        playerX = newX;
        playerY = newY;
        return true;
    }
    return false;
};


void GameMap::render(const Inventory& inv) const
{
    system("clear");
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (x == playerX && y == playerY)
            {
                std::cout << "P ";
            }
            else
            {
                std::cout << grid[y][x].getSymbol() << " ";
            }
        }
        printInventoryLine(y, inv);
        std::cout << "\n";
    }
}
void GameMap::initMap()
{
    grid[1][1].setTerrain(TerrainType::WATER);
    grid[2][2].setObject(std::make_shared<StaticObj>('#', false));
    grid[3][3].setObject(std::make_shared<StaticObj>('T', false));
}

bool GameMap::isValidPosition(int x, int y) const
{
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return grid[y][x].isPassable();
}

void GameMap::printInventoryLine(int line, const Inventory& inv) const
{
    const std::vector<std::string> invLines =
    {
        "HP: " + std::to_string(inv.hp),
        "Energy: " + std::to_string(inv.energy),
        "Gold: " + std::to_string(inv.gold),
        "Wood: " + std::to_string(inv.wood),
        "Stone: " + std::to_string(inv.stone)
    };

    if (line < int(invLines.size()))
    {
        std::cout << " | " << invLines[line];
    }
}
