#ifndef HEALCARD_H
#define HEALCARD_H

#include "Card.h"

class HealCard : public Card {

    std::string name;
    int healValue;
    int energyCost;

public:
    HealCard(std::string cardName, int healAmount, int cost);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
    int getEnergyCost() const override;
};

#endif