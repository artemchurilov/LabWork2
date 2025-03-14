/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/


#include "Tree.h"

char Tree::getSymbol() const
{
    return 'T';
}
bool Tree::isPassable() const
{
    return false;
}
void Tree::interact(GameState& state)
{
    state.inventory.energy -= 10;
    state.inventory.wood++;
}