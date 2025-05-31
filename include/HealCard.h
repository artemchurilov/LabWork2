/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef HEALCARD_H
#define HEALCARD_H
#include "Card.h"

/**
 * @brief A card that heals the player if the enemy is alive.
 */
class HealCard : public Card
{
    std::string name; ///< Name of the card.
    int healValue;    ///< Health points restored to the player.

public:
    /**
     * @brief Constructs a heal card.
     * @param cost Energy cost to play the card.
     * @param cardName Name of the card.
     * @param healAmount Health points to restore.
     */
    HealCard(int cost, std::string cardName, int healAmount);

    /**
     * @override
     * @brief Heals the player (only if the enemy is alive).
     */
    void play(CardPlayer& user, Enemy& target) override;

    /**
     * @override
     * @brief Returns the name of the card.
     */
    std::string getName() const override;
};

#endif