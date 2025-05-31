/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CARD_H
#define CARD_H

#include "CardPlayer.h"
#include "Enemy.h"
#include <string>

/**
 * @brief Abstract base class for game cards.
 * @details Cards have an energy cost and can be played by a player against an enemy.
 */
class Card
{
protected:
    int energyCost; ///< Energy cost required to play the card.

public:
    /**
     * @brief Constructs a card with a specified energy cost.
     * @param energy Initial energy cost of the card.
     */
    Card(int energy);

    /**
     * @brief Virtual destructor (default implementation).
     */
    virtual ~Card() = default;

    /**
     * @brief Plays the card, applying its effect.
     * @param user The player who uses the card.
     * @param target The enemy targeted by the card's effect.
     */
    virtual void play(CardPlayer& user, Enemy& target) = 0;

    /**
     * @brief Returns the name of the card.
     * @return Name of the card as a string.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Retrieves the current energy cost of the card.
     * @return Energy cost (int).
     */
    int getEnergyCost() const;

    /**
     * @brief Sets a new energy cost for the card.
     * @param amount New energy cost value.
     */
    void setEnergyCost(int amount);
};

#endif