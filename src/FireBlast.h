/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "EnemyCard.h"

class FireBlast : public EnemyCard {
    public:
        FireBlast() : EnemyCard(3) {}
        bool canUse(const CardPlayer& p, const Enemy& e) const override { return p.getHealth() < 30; e.isAlive(); }
        void execute(Enemy& user, CardPlayer& target) override { target.takeDamage(12); user.takeDamage(-2);}
        std::string getName() const override { return "Fire Blast"; }
    };
#endif