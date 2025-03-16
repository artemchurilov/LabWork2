/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Strike.h"
#include "CardPlayer.h"
#include "Enemy.h"

void Strike::play(CardPlayer& user, Enemy& target)
{
    target.takeDamage(6);
    user.loseEnergy(1);
}

std::string Strike::getName() const
{
    return "Strike";
}

int Strike::getEnergyCost() const
{
    return 1;
}
