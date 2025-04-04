/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/GameMap.h"
#include "../include/BossMob.h"
#include <iostream>
#include <cstdlib>
#include "../include/Tree.h"
#include "../include/Mob.h"
#include "../include/Campfire.h"
#include "../include/Stone.h"
#include "../include/Shop.h"
#include "../include/CardShop.h"

/**
 * @brief Initializes or resets the map layout.
 * @details Populates cells with objects:
 * - Default map: Campfire, Shop, Tree, Mobs, etc.
 * - Alternate map: BossMob and Campfire at specific positions.
 */
GameMap::GameMap(int w, int h) : width(w), height(h)
{
    grid.resize(h, std::vector<Cell>(w));
    initMap();
}

void GameMap::movePlayer(int dx, int dy, GameState& state)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    interactAt(newX, newY, state);

    if(isPassable(newX, newY))
    {
        playerX = newX;
        playerY = newY;
    }
}

void GameMap::render(const GameState& state) const
{
    std::cout << "\033c";
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
/**
 * @brief Renders inventory stats alongside the map.
 * @param line Line number to print (0-4 for HP, Energy, Gold, Wood, Stone).
 */
void GameMap::printInventoryLine(int line, const GameState& state) const
{
    const std::vector<std::string> lines =
    {
        "\033[91m HP\033[0m: " + std::to_string(state.inventory.hp),
        "\033[91m Energy\033[0m: " + std::to_string(state.inventory.energy),
        "\033[33m Gold\033[0m: " + std::to_string(state.inventory.gold),
        "\033[32m Wood\033[0m: " + std::to_string(state.inventory.wood),
        "\033[90m Stone\033[0m: " + std::to_string(state.inventory.stone)
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
/**
 * @brief Switches between default and alternate map layouts.
 * @note Resets player position to (0,0) and ensures it's passable.
 */
void GameMap::toggleMap()
{
    alternateMap = !alternateMap;
    initMap();
    playerX = 0;
    playerY = 0;
    if(!isPassable(0, 0))
    {
        grid[0][0].setObject(nullptr);
    }
}

bool GameMap::isPassable(int x, int y) const
{
    if(x < 0 || x >= width || y < 0 || y >= height) return false;
    return grid[y][x].isPassable();
}

void GameMap::initMap()
{
    for(auto& row : grid)
    {
        for(auto& cell : row)
        {
            cell = Cell();
        }
    }

    if(!alternateMap)
    {
        grid[0][0] = Cell();
        grid[3][1].setObject(std::make_shared<Campfire>());
        grid[4][2].setObject(std::make_shared<Shop>());
        grid[1][2].setObject(std::make_shared<Tree>());
        grid[4][4].setObject(std::make_shared<Stone>());
        grid[2][3].setObject(std::make_shared<Mob>('M', 20, 10));
        grid[0][4].setObject(std::make_shared<Mob>('D', 1000, 50));
        grid[2][2].setObject(std::make_shared<CardShop>());

    }
    else
    {
        grid[0][0] = Cell();
        grid[2][2].setObject(std::make_shared<Campfire>());
        grid[2][4].setObject(std::make_shared<BossMob>());
    }
}
