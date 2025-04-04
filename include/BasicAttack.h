
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BASICATTACK_H
#define BASICATTACK_H
#include "EnemyCard.h"
#include "CardPlayer.h"

/**
 * @brief A basic enemy attack card with low priority.
 * @details Deals moderate damage to the player. Always usable if both enemy and player are alive.
 */
class BasicAttack : public EnemyCard
{
public:
    /**
     * @brief Constructs the card with priority 1.
     */
    BasicAttack();

    /**
     * @override
     * @brief Checks if the card can be used (always returns true if both entities are alive).
     * @note The check for player/enemy being alive has no effect on the return value in the current implementation.
     * @return true (unconditionally).
     */
    bool canUse(const CardPlayer& p, const Enemy& e) const override;

    /**
     * @override
     * @brief Deals 8 damage to the player.
     */
    void execute(Enemy& user, CardPlayer& target) override;

    /**
     * @override
     * @brief Returns the card's name.
     */
    std::string getName() const override;
};

#endif