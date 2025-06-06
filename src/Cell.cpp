/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "../include/Cell.h"


Cell::Cell(): terrain(TerrainType::GROUND) {}

void Cell::setTerrain(TerrainType t)
{
    terrain = t;
}

void Cell::setObject(std::shared_ptr<GameObject> obj)
{
    object = obj;
}

bool Cell::isPassable() const
{
    if (terrain == TerrainType::WATER) return false;
    return object ? object->isPassable() : true;
}

char Cell::getSymbol() const
{
    if (object) return object->getSymbol();
    return terrain == TerrainType::GROUND ? '.' : '~';
}

void Cell::interact(GameState& state) const
{
    if (object) object->interact(state);
}