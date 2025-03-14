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
    state.inventory.hp = 100;
    state.inventory.energy = 50;
    state.day++;

};