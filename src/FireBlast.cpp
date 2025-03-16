
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "FireBlast.h"

bool FireBlast::canUse(const CardPlayer& p, const Enemy& e) const
{
    return p.getHealth() < 30;
    e.isAlive();
};

FireBlast::FireBlast() : EnemyCard(3) {}
void FireBlast::execute(Enemy& user, CardPlayer& target)
{
    target.takeDamage(12);
    user.takeDamage(-2);
};

std::string FireBlast::getName() const
{
    return "Fire Blast";
};