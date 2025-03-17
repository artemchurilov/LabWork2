#ifndef FISTPUNCH_H
#define FISTPUNCH_H

#include "Card.h"

class FistPunch : public Card {
    public:
        void play(CardPlayer& user, Enemy& target) override;
        std::string getName() const override;
        int getEnergyCost() const override;
    };

#endif