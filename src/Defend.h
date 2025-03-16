/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DEFEND_H
#define DEFEND_H
#include <iostream>
#include  "Enemy.h"
#include "CardPlayer.h"
#include "Card.h"

class Defend : public Card
{
public:
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
    int getEnergyCost() const override;
};

#endif