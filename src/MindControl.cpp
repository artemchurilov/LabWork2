
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/MindControl.h"


MindControl::MindControl() : EnemyCard(2) {}

bool MindControl::canUse(const CardPlayer& p, const Enemy& e) const
{
    return (p.getBlock() > 0) & (e.isAlive());
}
void MindControl::execute(Enemy& user, CardPlayer& target)
{
    target.addWeak(2);
    user.takeDamage(-2);
}
std::string MindControl::getName() const
{
    return "Mind Control";
}

