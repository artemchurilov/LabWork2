/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef STRIKE_H
#define STRIKE_H
#include "Card.h"
class Strike : public Card {
    public:
        void play(CardPlayer& user, Enemy& target) override;
        std::string getName() const override { return "Strike"; }
        int getEnergyCost() const override { return 1; }
    };

#endif