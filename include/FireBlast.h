/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef FIREBLAST_H
#define FIREBLAST_H
#include "EnemyCard.h"
#include "CardPlayer.h"
class FireBlast : public EnemyCard
{
public:
    FireBlast();
    bool canUse(const CardPlayer& p, const Enemy& e) const override;
    void execute(Enemy& user, CardPlayer& target) override;
    std::string getName() const override;
};

#endif