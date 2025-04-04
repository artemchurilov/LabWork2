/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <memory>
#include "EnemyCard.h"
#include "CardPlayer.h"

// Forward declarations
class EnemyCard;
class CardPlayer;

/**
 * @brief Represents an enemy entity in the game.
 * @details Enemies have health and a set of action cards they use to attack the player.
 */
class Enemy
{
    int health = 100; ///< Current health of the enemy.
    std::vector<std::unique_ptr<EnemyCard>> cards; ///< Action cards available to the enemy.

public:
    /**
     * @brief Constructs an enemy with default health and initializes action cards.
     */
    Enemy();

    /**
     * @brief Retrieves the current health of the enemy.
     * @return Current health value.
     */
    int getHealth();

    /**
     * @brief Applies damage to the enemy.
     * @param amount Amount of damage to apply.
     */
    void takeDamage(int amount);

    /**
     * @brief Checks if the enemy is alive.
     * @return true if health > 0, false otherwise.
     */
    bool isAlive() const;

    /**
     * @brief Executes the enemy's turn by using available action cards.
     * @details The enemy uses up to two highest-priority cards that can be used.
     * @param target Player targeted by the enemy's actions.
     */
    void executeTurn(CardPlayer& target);

    /**
     * @brief Sets the enemy's health to a specific value.
     * @param health New health value.
     */
    void setHealth(int health);

    /**
     * @brief Prints the enemy's current status to the console.
     */
    void printStatus() const;
};

#endif