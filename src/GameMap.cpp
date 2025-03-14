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

void GameMap::movePlayer(int dx, int dy, GameState& state) {
    int newX = playerX + dx;
    int newY = playerY + dy;
    
    interactAt(newX, newY, state);
    
    if(isPassable(newX, newY)) {
        playerX = newX;
        playerY = newY;
    }
}

void GameMap::render(const GameState& state) const
{
    system("clear");
    std::cout << "Day: " << state.day << "\n\n";

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            std::cout << (x == playerX && y == playerY ? 'P' : grid[y][x].getSymbol()) << " ";
        }
        printInventoryLine(y, state);
        std::cout << "\n";
    }
    std::cout << "\n" << state.last_message << "\n";
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

void GameMap::getPlayerPos(int& x, int& y) const
{
    x = playerX;
    y = playerY;
}

void GameMap::setPlayerPos(int x, int y)
{
    playerX = x;
    playerY = y;
}

void GameMap::interactAt(int x, int y, GameState& state)
{
    if(x >= 0 && x < width && y >= 0 && y < height)
    {
        grid[y][x].interact(state);
    }
}

void GameMap::toggleMap() {
    alternateMap = !alternateMap;
    initMap();
    
    playerX = 0;
    playerY = 0;
    
    if(!isPassable(0, 0)) {
        grid[0][0].setObject(nullptr);
    }
};

bool GameMap::isPassable(int x, int y) const
{
    if(x < 0 || x >= width || y < 0 || y >= height) return false;
    return grid[y][x].isPassable();
}

void GameMap::initMap() {
    for(auto& row : grid) {
        for(auto& cell : row) {
            cell = Cell();
        }
    }

    if(!alternateMap) {
        grid[0][0] = Cell();
        grid[3][1].setObject(std::make_shared<Campfire>());
        grid[4][2].setObject(std::make_shared<Shop>());
        grid[1][2].setObject(std::make_shared<Tree>());
        grid[4][4].setObject(std::make_shared<Stone>());
        grid[2][3].setObject(std::make_shared<Mob>('M', 20, 10));
        grid[0][4].setObject(std::make_shared<Mob>('D', 1000, 50));
    } else {
        grid[0][0] = Cell();
        grid[2][2].setObject(std::make_shared<Campfire>());
    }
}
