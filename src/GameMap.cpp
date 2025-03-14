/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "GameMap.h"
#include <iostream>
#include "StaticObj.h"
#include <cstdlib>
#include "Tree.h"
#include "Mob.h"
#include "Campfire.h"
#include "Stone.h"
#include "Shop.h"

GameMap::GameMap(int w, int h) : width(w), height(h)
{
    grid.resize(h, std::vector<Cell>(w));
    initMap();
}

bool GameMap::movePlayer(int dx, int dy, GameState& state)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (newX < 0 || newX >= width || newY < 0 || newY >= height) return false;

    grid[newY][newX].interact(state);

    if (grid[newY][newX].isPassable())
    {
        playerX = newX;
        playerY = newY;
        return true;
    }
    return false;
}

void GameMap::render(const GameState& state) const {
    system("clear");
    std::cout << "Day: " << state.day << "\n\n";
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << (x == playerX && y == playerY ? 'P' : grid[y][x].getSymbol()) << " ";
        }
        printInventoryLine(y, state);
        std::cout << "\n";
    }
    std::cout << "\n" << state.last_message << "\n";
}


void GameMap::initMap() {
    grid[4][2].setObject(std::make_shared<Shop>());
    grid[1][2].setObject(std::make_shared<Tree>());
    grid[3][1].setObject(std::make_shared<Campfire>());
    grid[4][4].setObject(std::make_shared<Stone>());
    grid[2][3].setObject(std::make_shared<Mob>('M', 20, 10));
    grid[0][4].setObject(std::make_shared<Mob>('D', 1000, 50));
}


void GameMap::printInventoryLine(int line, const GameState& state) const
{
    const std::vector<std::string> lines =
    {
        "HP: " + std::to_string(state.inventory.hp),
        "Energy: " + std::to_string(state.inventory.energy),
        "Gold: " + std::to_string(state.inventory.gold),
        "Wood: " + std::to_string(state.inventory.wood),
        "Stone: " + std::to_string(state.inventory.stone)
    };
    if (line < int(lines.size())) std::cout << " | " << lines[line];
}