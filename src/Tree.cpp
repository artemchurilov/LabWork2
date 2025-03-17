/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/


#include "../include/Tree.h"

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
    if(state.inventory.energy >= 10)
    {
        state.inventory.energy -= 10;
        state.inventory.wood++;
        state.last_message = "Chopped tree! +1 Wood";
    }
    else
    {
        state.last_message = "Not enough energy!";
    }
}