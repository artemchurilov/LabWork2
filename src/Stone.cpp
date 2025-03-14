

/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Stone.h"

char Stone::getSymbol() const
{
    return 'S';
};

bool Stone::isPassable() const
{
    return false;
}

void Stone::interact(GameState& state) const
{
    state.inventory.energy -= 15;
    state.inventory.stone++;
}