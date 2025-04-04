
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ENEMYCARD_H
#define ENEMYCARD_H

#include <iostream>

// Forward declarations
class Enemy;
class CardPlayer;

/**
 * @brief Abstract base class for enemy action cards.
 * @details These cards define behaviors enemies can use against players.
 *          Each card has a priority (determines execution order) and conditional logic for use.
 */
class EnemyCard
{
    int priority; ///< Priority of the card (higher values may execute earlier).

public:
    /**
     * @brief Constructs an enemy card with a priority value.
     * @param p Priority of the card.
     */
    EnemyCard(int p);

    /**
     * @brief Virtual destructor (default implementation).
     * @note Required for polymorphic behavior in derived classes.
     */
    virtual ~EnemyCard() = default;

    /**
     * @brief Executes the card's effect.
     * @param user The enemy using the card.
     * @param target The player targeted by the card.
     */
    virtual void execute(Enemy& user, CardPlayer& target) = 0;

    /**
     * @brief Checks if the card can be used under current conditions.
     * @param p Reference to the targeted player.
     * @param e Reference to the enemy using the card.
     * @return true if the card can be used, false otherwise.
     */
    virtual bool canUse(const CardPlayer& p, const Enemy& e) const = 0;

    /**
     * @brief Returns the priority of the card.
     * @return Priority value (int).
     */
    int getPriority() const;

    /**
     * @brief Returns the name of the card.
     * @return Name of the card as a string.
     */
    virtual std::string getName() const = 0;
};

#endif