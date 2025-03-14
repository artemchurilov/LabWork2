/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CELL_H
#define CELL_H

#include <memory>
#include "GameObject.h"

enum class TerrainType { GROUND, WATER };


class Cell {
    public:
        Cell();
        void setTerrain(TerrainType type);
        void setObject(std::shared_ptr<GameObject> obj);
        char getSymbol() const;
        bool isPassable() const;
    private:
        TerrainType terrain;
        std::shared_ptr<GameObject> object;
    };
#endif