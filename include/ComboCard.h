/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef COMBOCARD_H
#define COMBOCARD_H


#include "Card.h"

class ComboCard : public Card
{

    std::string name;
    int damage;
    int block;

public:
    ComboCard(int cost, std::string cardName, int damageValue, int blockValue);
    void play(CardPlayer& user, Enemy& target) override;
    std::string getName() const override;
};

#endif