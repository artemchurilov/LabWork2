#ifndef ATTACKCARD_H
#define ATTACKCARD_H
#include "Card.h"

class AttackCard : public Card {

    std::string name;
    int damage;
    int energyCost;

public:
    AttackCard(std::string cardName, int damageValue, int cost);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
    int getEnergyCost() const override;
};

#endif