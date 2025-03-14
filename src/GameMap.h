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
    void movePlayer(int dx, int dy, GameState& state);
    void render(const GameState& state) const;
    void interactAt(int x, int y, GameState& state);
    void getPlayerPos(int& x, int& y) const;
    void setPlayerPos(int x, int y);
    void toggleMap();


    void placeObject(int x, int y, std::shared_ptr<GameObject> obj);
    void printInventoryLine(int line, const GameState& state) const;
    void initMap();
    bool isPassable(int x, int y) const;

private:



    int width, height;
    int playerX = 0, playerY = 0;
    bool alternateMap = false;
    std::vector<std::vector<Cell>> grid;

};

#endif