
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Defend.h"

void Defend::play(CardPlayer& user, Enemy& target)
{
    user.addBlock(5);
    user.loseEnergy(1);
    target.isAlive();
}

std::string Defend::getName() const
{
    return "Defend";
}

int Defend::getEnergyCost() const
{
    return 1;
}