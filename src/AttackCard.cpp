/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/AttackCard.h"

AttackCard::AttackCard(int cost, std::string cardName, int damageValue)
    : Card(cost),name(cardName), damage(damageValue)
{
}

void AttackCard::play(CardPlayer& user, Enemy& target)
{
    target.takeDamage(damage);
    user.loseEnergy(energyCost);
}

std::string AttackCard::getName() const
{
    return name;
}

