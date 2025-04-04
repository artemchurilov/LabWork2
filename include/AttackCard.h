/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ATTACKCARD_H
#define ATTACKCARD_H
#include "Card.h"

/**
 * @brief A card that deals damage to an enemy.
 * @details Inherits from the base Card class.
 */
class AttackCard : public Card
{
    std::string name; ///< Name of the card.
    int damage;       ///< Damage value to apply to the enemy.

public:
    /**
     * @brief Constructs an attack card.
     * @param cost Energy cost to play the card.
     * @param cardName Name of the card.
     * @param damageValue Damage dealt to the enemy.
     */
    AttackCard(int cost, std::string cardName, int damageValue);

    /**
     * @override
     * @brief Deals damage to the target and deducts energy from the player.
     * @param user The player using the card.
     * @param target The enemy receiving the damage.
     */
    void play(CardPlayer& user, Enemy& target) override;

    /**
     * @override
     * @brief Returns the name of the card.
     * @return Card name as a string.
     */
    std::string getName() const override;
};

#endif