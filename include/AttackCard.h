/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ATTACKCARD_H
#define ATTACKCARD_H
#include "Card.h"

class AttackCard : public Card
{

    std::string name;
    int damage;

public:

    AttackCard(int cost,std::string cardName, int damageValue);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
};

#endif