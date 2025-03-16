
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "BasicAttack.h"

BasicAttack::BasicAttack() : EnemyCard(1)
{

}

bool BasicAttack::canUse(const CardPlayer& p, const Enemy& e) const
{
    p.isAlive();
    e.isAlive();
    return true;
}

void BasicAttack::execute(Enemy& user, CardPlayer& target)
{
    target.takeDamage(8);
    user.isAlive();
}

std::string BasicAttack::getName() const
{
    return "Basic Attack";
}