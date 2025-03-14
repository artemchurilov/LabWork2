/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Cell.h"


Cell::Cell(): terrain(TerrainType::GROUND), obj(nullptr) {}
        
char Cell::getSymbol() const{
    if (obj) return obj->getSymbol();
    return terrain == TerrainType::GROUND ? '.' : '#';
}

void Cell::setObject(std::shared_ptr<GameObject> object)
{ obj = object; }

void Cell::setTerrain(TerrainType type) 
{ terrain = type; }