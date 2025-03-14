
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BASICATTACK_H
#define BASICATTACK_H
#include "EnemyCard.h"
#include "CardPlayer.h"

class BasicAttack : public EnemyCard {
    public:
        BasicAttack() : EnemyCard(1) {}
        bool canUse(const CardPlayer& p, const Enemy& e) const override;
        void execute(Enemy& user, CardPlayer& target) override { target.takeDamage(8); user.isAlive(); }
        std::string getName() const override { return "Basic Attack"; }
    };

#endif