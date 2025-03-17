#ifndef COMBOCARD_H
#define COMBOCARD_H


#include "Card.h"

class ComboCard : public Card {

    std::string name;
    int damage;
    int block;
    int energyCost;

public:
    ComboCard(std::string cardName, int damageValue, int blockValue, int cost);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
    int getEnergyCost() const override;
};

#endif