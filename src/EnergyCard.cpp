#include "EnergyCard.h"

EnergyCard::EnergyCard(std::string cardName, int damageToSelf, int energyBoost, int cost)
    : name(cardName), selfDamage(damageToSelf), energyGain(energyBoost), energyCost(cost) {}

void EnergyCard::play(CardPlayer& user, Enemy& target) {
    if(target.isAlive()){
    user.takeDamage(selfDamage);
    user.loseEnergy(-energyCost);
    }
}

std::string EnergyCard::getName() const {
    return name;
}

int EnergyCard::getEnergyCost() const {
    return energyCost;
}
