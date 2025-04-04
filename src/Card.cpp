/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Card.h"

int Card::getEnergyCost() const
{
    return energyCost;
}

void Card::setEnergyCost(int amount)
{
    energyCost = amount;
}

Card::Card(int energy):energyCost(energy){};