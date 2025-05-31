/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DEFEND_H
#define DEFEND_H
#include "Card.h"

/**
 * @brief A card that grants block to the player if the enemy is alive.
 */
class DefendCard : public Card
{
    std::string name; ///< Name of the card.
    int block;        ///< Block value granted to the player.

public:
    /**
     * @brief Constructs a defend card.
     * @param cost Energy cost to play the card.
     * @param cardName Name of the card.
     * @param blockValue Block value to add.
     */
    DefendCard(int cost, std::string cardName, int blockValue);

    /**
     * @override
     * @brief Adds block to the player (only if the enemy is alive).
     */
    void play(CardPlayer& user, Enemy& target) override;

    /**
     * @override
     * @brief Returns the name of the card.
     */
    std::string getName() const override;
};

#endif