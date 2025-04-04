/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef FIREBLAST_H
#define FIREBLAST_H
#include "EnemyCard.h"
#include "CardPlayer.h"

/**
 * @brief High-priority card that deals heavy damage when the player is weakened.
 * @details Also heals the enemy slightly.
 */
class FireBlast : public EnemyCard
{
public:
    /**
     * @brief Constructs the card with priority 3.
     */
    FireBlast();

    /**
     * @override
     * @brief Checks if the player's health is below 30.
     * @return true if player's health < 30.
     */
    bool canUse(const CardPlayer& p, const Enemy& e) const override;

    /**
     * @override
     * @brief Deals 12 damage to the player and heals the enemy by 2 HP.
     */
    void execute(Enemy& user, CardPlayer& target) override;

    /**
     * @override
     * @brief Returns the card's name.
     */
    std::string getName() const override;
};

#endif