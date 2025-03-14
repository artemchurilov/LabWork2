
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ENEMYCARD_H
#define ENEMYCARD_H
#include <iostream>
class Enemy;
class CardPlayer;
class EnemyCard {
    int priority;
public:
    EnemyCard(int p) : priority(p) {}
    virtual ~EnemyCard() = default;
    virtual void execute(Enemy& user, CardPlayer& target) = 0;
    virtual bool canUse(const CardPlayer& p, const Enemy& e) const = 0;
    int getPriority() const { return priority; }
    virtual std::string getName() const = 0;
};


#endif