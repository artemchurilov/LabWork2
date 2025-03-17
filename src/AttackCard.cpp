/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/AttackCard.h"

AttackCard::AttackCard(std::string cardName, int damageValue, int cost)
    : name(cardName), damage(damageValue), energyCost(cost) {}

void AttackCard::play(CardPlayer& user, Enemy& target)
{
    target.takeDamage(damage);
    user.loseEnergy(energyCost);
}

std::string AttackCard::getName() const
{
    return name;
}

int AttackCard::getEnergyCost() const
{
    return energyCost;
}
