/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <vector>
#include "Cell.h"

class Map {
    public:
        Map(int width, int height);
        void placeObject(int x, int y, std::shared_ptr<GameObject> obj);
        void render() const;
    private:
        int width, height;
        std::vector<std::vector<Cell>> grid;
    };
    
#endif