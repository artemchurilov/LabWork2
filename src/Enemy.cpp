
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Enemy.h"
#include "../include/BasicAttack.h"
#include "../include/FireBlast.h"
#include "../include/MindControl.h"
#include <algorithm>

Enemy::Enemy()
{
    cards.push_back(std::make_unique<BasicAttack>());
    cards.push_back(std::make_unique<FireBlast>());
    cards.push_back(std::make_unique<MindControl>());
}

int Enemy::getHealth()
{
    return health;
}
void Enemy::takeDamage(int amount)
{
    health -= amount;
}

bool Enemy::isAlive()const
{
    return health > 0;
};

void Enemy::executeTurn(CardPlayer& target)
{
    std::vector<EnemyCard*> available;
    for(auto& card : cards)
    {
        if(card->canUse(target, *this))
        {
            available.push_back(card.get());
        }
    }

    std::sort(available.begin(), available.end(),
              [](auto a, auto b)
    {
        return a->getPriority() > b->getPriority();
    });

    int actions = 0;
    for(auto card : available)
    {
        if(actions >= 2) break;
        std::cout << "Enemy uses " << card->getName() << "!\n";
        card->execute(*this, target);
        actions++;
    }
}

void Enemy::printStatus() const
{
    std::cout << "\n[Enemy]\nHP: " << health << "\n";
}

