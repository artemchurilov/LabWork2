/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef MINDCONTROL_H
#define MINDCONTROL_H

#include "EnemyCard.h"
#include "CardPlayer.h"

class MindControl : public EnemyCard
{
public:
    MindControl();
    bool canUse(const CardPlayer& p, const Enemy& e) const override;
    void execute(Enemy& user, CardPlayer& target) override;
    std::string getName() const override;
};
#endif