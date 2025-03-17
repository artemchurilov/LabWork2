/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/HealCard.h"

HealCard::HealCard(std::string cardName, int healAmount, int cost)
    : name(cardName), healValue(healAmount), energyCost(cost) {}

void HealCard::play(CardPlayer& user, Enemy& target)
{
    if (target.isAlive())
    {

        user.heal(healValue);
        user.loseEnergy(energyCost);
    }
}

std::string HealCard::getName() const
{
    return name;
}

int HealCard::getEnergyCost() const
{
    return energyCost;
}