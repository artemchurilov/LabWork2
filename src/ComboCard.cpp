#include "ComboCard.h"

ComboCard::ComboCard(std::string cardName, int damageValue, int blockValue, int cost)
    : name(cardName), damage(damageValue), block(blockValue), energyCost(cost) {}

void ComboCard::play(CardPlayer& user, Enemy& target) {
    target.takeDamage(damage); 
    user.addBlock(block);       
    user.loseEnergy(energyCost);
}

std::string ComboCard::getName() const {
    return name;
}

int ComboCard::getEnergyCost() const {
    return energyCost;
}
