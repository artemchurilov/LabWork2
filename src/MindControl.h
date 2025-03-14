/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef MINDCONTROL_H
#define MINDCONTROL_H

#include "EnemyCard.h"
class MindControl : public EnemyCard {
    public:
        MindControl() : EnemyCard(2) {}
        bool canUse(const CardPlayer& p, const Enemy& e) const override { return (p.getBlock() > 0) & (e.isAlive());}
        void execute(Enemy& user, CardPlayer& target) override { target.addWeak(2); user.takeDamage(-2); }
        std::string getName() const override { return "Mind Control"; }
    };
#endif