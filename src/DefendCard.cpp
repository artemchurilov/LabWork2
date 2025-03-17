#include "DefendCard.h"

DefendCard::DefendCard(std::string cardName, int blockValue, int cost) 
    : name(cardName), block(blockValue), energyCost(cost) {}

void DefendCard::play(CardPlayer& user, Enemy& target) {
    if (target.isAlive()){
        user.addBlock(block);
        user.loseEnergy(energyCost);
    }
}

std::string DefendCard::getName() const {
    return name;
}

int DefendCard::getEnergyCost() const {
    return energyCost;
}
