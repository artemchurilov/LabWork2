/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/ComboCard.h"

ComboCard::ComboCard(int cost, std::string cardName, int damageValue, int blockValue)
    : Card(cost), name(cardName), damage(damageValue), block(blockValue) {}

void ComboCard::play(CardPlayer& user, Enemy& target)
{
    target.takeDamage(damage);
    user.addBlock(block);
    user.loseEnergy(energyCost);
}

std::string ComboCard::getName() const
{
    return name;
}
