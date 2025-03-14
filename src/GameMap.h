/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <memory>
#include <vector>
#include "Inventory.h"
#include "Cell.h"

class GameMap {
    public:
        GameMap(int width, int height);
        bool movePlayer(int dx, int dy);
        void placeObject(int x, int y, std::shared_ptr<GameObject> obj);
        void render(const Inventory& inv) const;
    private:
        void initMap();
        bool isValidPosition(int x, int y) const;
        void printInventoryLine(int line, const Inventory& inv) const;

        int width, height;
        int playerX = 0, playerY = 0;
        std::vector<std::vector<Cell>> grid;
    };
    
#endif