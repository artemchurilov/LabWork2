
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Enemy.h"
#include "../include/BasicAttack.h"
#include "../include/FireBlast.h"
#include "../include/MindControl.h"
#include <algorithm>

/**
 * @brief Constructs an enemy and initializes its action cards.
 * @details Adds BasicAttack, FireBlast, and MindControl cards to the enemy's deck.
 */
Enemy::Enemy()
{
    cards.push_back(std::make_unique<BasicAttack>());
    cards.push_back(std::make_unique<FireBlast>());
    cards.push_back(std::make_unique<MindControl>());
}

/**
 * @brief Sets the enemy's health to a specific value.
 * @param health New health value.
 */
void Enemy::setHealth(int health)
{
    health = health; // Note: This implementation has a bug (parameter shadows member variable).
}

/**
 * @brief Retrieves the current health of the enemy.
 * @return Current health value.
 */
int Enemy::getHealth()
{
    return health;
}

/**
 * @brief Applies damage to the enemy, reducing its health.
 * @param amount Damage amount.
 */
void Enemy::takeDamage(int amount)
{
    health -= amount;
}

/**
 * @brief Checks if the enemy is alive.
 * @return true if health > 0, false otherwise.
 */
bool Enemy::isAlive() const
{
    return health > 0;
}

/**
 * @brief Executes the enemy's turn by selecting and using up to two highest-priority actions.
 * @details Collects all usable cards, sorts them by priority (descending), and executes the top two.
 * @param target Player targeted by the enemy's actions.
 */
void Enemy::executeTurn(CardPlayer& target)
{
    std::vector<EnemyCard*> available;
    for (auto& card : cards)
    {
        if (card->canUse(target, *this))
        {
            available.push_back(card.get());
        }
    }

    // Sort cards by descending priority
    std::sort(available.begin(), available.end(),
              [](auto a, auto b)
    {
        return a->getPriority() > b->getPriority();
    });

    int actions = 0;
    for (auto card : available)
    {
        if (actions >= 2) break;
        std::cout << "Enemy uses " << card->getName() << "!\n";
        card->execute(*this, target);
        actions++;
    }
}

/**
 * @brief Prints the enemy's health to the console.
 */
void Enemy::printStatus() const
{
    std::cout << "\n[Enemy]\nHP: " << health << "\n";
}