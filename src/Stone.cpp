/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Stone.h"

char Stone::getSymbol() const
{
    return 'S';
};

bool Stone::isPassable() const
{
    return false;
}

void Stone::interact(GameState& state)
{
    if(state.inventory.energy >= 15)
    {
        state.inventory.energy -= 15;
        state.inventory.stone++;
        state.last_message = "Mined stone! +1 Stone";
    }
    else
    {
        state.last_message = "Not enough energy!";
    }
}