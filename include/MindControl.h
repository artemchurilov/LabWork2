/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef MINDCONTROL_H
#define MINDCONTROL_H
#include "EnemyCard.h"
#include "CardPlayer.h"

/**
 * @brief Applies the "Weak" effect to the player and heals the enemy.
 * @details Medium priority card.
 */
class MindControl : public EnemyCard
{
public:
    /**
     * @brief Constructs the card with priority 2.
     */
    MindControl();

    /**
     * @override
     * @brief Checks if the player has block and the enemy is alive.
     * @return true if player's block > 0 and enemy is alive.
     */
    bool canUse(const CardPlayer& p, const Enemy& e) const override;

    /**
     * @override
     * @brief Adds 2 turns of "Weak" to the player and heals the enemy by 2 HP.
     */
    void execute(Enemy& user, CardPlayer& target) override;

    /**
     * @override
     * @brief Returns the card's name.
     */
    std::string getName() const override;
};

#endif