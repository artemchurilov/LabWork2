#ifndef DEFEND_H
#define DEFEND_H

#include "Card.h"

class DefendCard : public Card {

    std::string name;
    int block;
    int energyCost;

public:
    DefendCard(std::string cardName, int blockValue, int cost);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
    int getEnergyCost() const override;
};

#endif