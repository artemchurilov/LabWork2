/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <memory>
#include <vector>
#include "Cell.h"

class GameMap
{
public:
    GameMap(int width, int height);
    bool movePlayer(int dx, int dy, GameState& state);
    void render(const GameState& state) const;

private:
    void placeObject(int x, int y, std::shared_ptr<GameObject> obj);
    void initMap();
    void printInventoryLine(int line, const GameState& state) const;
    int width, height;
    int playerX = 0, playerY = 0;
    std::vector<std::vector<Cell>> grid;
};

#endif