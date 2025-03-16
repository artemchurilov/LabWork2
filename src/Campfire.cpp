/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Campfire.h"

char Campfire::getSymbol() const
{
    return 'C';
}

void Campfire::interact(GameState& state)
{
    if(state.inventory.hp < 100 || state.inventory.energy < 50)
    {
        state.inventory.hp = 100;
        state.inventory.energy = 50;
        state.day++;
        state.last_message = "Restored health and energy! New day: " + std::to_string(state.day);
    }
    else
    {
        state.last_message = "Already fully rested!";
    }
};