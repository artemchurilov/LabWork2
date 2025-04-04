/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DEFEND_H
#define DEFEND_H

#include "Card.h"

class DefendCard : public Card
{

    std::string name;
    int block;

public:
    DefendCard(int cost, std::string cardName, int blockValue);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
};

#endif