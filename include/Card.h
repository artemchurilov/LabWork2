/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CARD_H
#define CARD_H

#include "CardPlayer.h"
#include "Enemy.h"
#include <string>

class Card
{
protected:
    int energyCost;
public:
    Card(int energy);
    virtual ~Card() = default;
    virtual void play(CardPlayer& user, Enemy& target) = 0;
    virtual std::string getName() const = 0;
    int getEnergyCost() const;
    void setEnergyCost(int amount);
};

#endif