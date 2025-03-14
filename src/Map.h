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
        void setCell(int x, int y, CellType type);
        void render() const;
    
    private:
        int width, height;
        std::vector<std::vector<std::shared_ptr<Cell>>> grid;
    };
    
#endif