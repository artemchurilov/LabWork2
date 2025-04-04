/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef COMBOCARD_H
#define COMBOCARD_H
#include "Card.h"

/**
 * @brief A card that deals damage and grants block to the player.
 */
class ComboCard : public Card
{
    std::string name; ///< Name of the card.
    int damage;      ///< Damage dealt to the enemy.
    int block;       ///< Block granted to the player.

public:
    /**
     * @brief Constructs a combo card.
     * @param cost Energy cost to play the card.
     * @param cardName Name of the card.
     * @param damageValue Damage dealt to the enemy.
     * @param blockValue Block granted to the player.
     */
    ComboCard(int cost, std::string cardName, int damageValue, int blockValue);

    /**
     * @override
     * @brief Deals damage, adds block, and deducts energy.
     */
    void play(CardPlayer& user, Enemy& target) override;

    /**
     * @override
     * @brief Returns the name of the card.
     */
    std::string getName() const override;
};

#endif