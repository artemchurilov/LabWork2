#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"

class EnergyCard : public Card {
    std::string name;
    int selfDamage;
    int energyGain;
    int energyCost;

public:
    EnergyCard(std::string cardName, int damageToSelf, int energyBoost, int cost);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
    int getEnergyCost() const override;
};
#endif