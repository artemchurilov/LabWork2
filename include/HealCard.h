/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef HEALCARD_H
#define HEALCARD_H

#include "Card.h"

class HealCard : public Card
{

    std::string name;
    int healValue;

public:
    HealCard(int cost, std::string cardName, int healAmount);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
};

#endif