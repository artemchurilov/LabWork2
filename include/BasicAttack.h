
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BASICATTACK_H
#define BASICATTACK_H
#include "EnemyCard.h"
#include "CardPlayer.h"

class BasicAttack : public EnemyCard
{
public:
    BasicAttack();
    bool canUse(const CardPlayer& p, const Enemy& e) const override;
    void execute(Enemy& user, CardPlayer& target) override;
    std::string getName() const override;
};

#endif