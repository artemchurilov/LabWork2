/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef CARDPLAYER_H
#define CARDPLAYER_H

#include <vector>
#include <memory>
#include "Card.h"

class Card;

/**
 * @brief Represents a player who uses cards in the game.
 * @details Manages the player's state: health, energy, block, hand, and deck.
 */
class CardPlayer
{
    int health = 50;        ///< Current health of the player.
    int block = 0;          ///< Current block (absorbs damage).
    int energy = 3;         ///< Current energy (used to play cards).
    int weak = 0;           ///< Number of turns with the "Weak" effect (reduces block by 25%).
    std::vector<std::unique_ptr<Card>> hand; ///< Cards currently in the player's hand.

public:
    std::vector<std::unique_ptr<Card>> deck; ///< The player's deck of cards.

    /**
     * @brief Default constructor for the player.
     */
    CardPlayer();

    /**
     * @brief Restores the player's health.
     * @param amount Health points to restore.
     */
    void heal(int amount);

    /**
     * @brief Draws cards from the deck into the hand.
     * @param count Number of cards to draw.
     */
    void drawCards(int count);

    /**
     * @brief Starts the player's turn: resets energy, draws cards, and reduces status effects.
     */
    void startTurn();

    /**
     * @brief Reduces the player's energy.
     * @param amount Amount of energy to lose.
     */
    void loseEnergy(int amount);

    /**
     * @brief Adds block to the player.
     * @param amount Base block value (weakened by 25% if "Weak" is active).
     */
    void addBlock(int amount);

    /**
     * @brief Applies damage to the player, considering block.
     * @param amount Damage amount.
     */
    void takeDamage(int amount);

    /**
     * @brief Applies the "Weak" effect to the player.
     * @param turns Duration of the effect in turns.
     */
    void addWeak(int turns);

    /**
     * @brief Sets the player's energy to a specific value.
     * @param amount New energy value.
     */
    void setEnergy(int amount);

    /**
     * @brief Sets the player's health to a specific value.
     * @param amount New health value.
     */
    void setHealth(int amount);

    /**
     * @brief Checks if the player is alive.
     * @return true if health > 0, false otherwise.
     */
    bool isAlive() const;

    /**
     * @brief Prints the player's current status to the console.
     */
    void printStatus() const;

    /**
     * @brief Returns the cards in the player's hand.
     * @return Reference to the hand vector.
     */
    std::vector<std::unique_ptr<Card>>& getHand();

    /**
     * @brief Returns the player's current energy.
     * @return Energy value.
     */
    int getEnergy() const;

    /**
     * @brief Returns the player's current health.
     * @return Health value.
     */
    int getHealth() const;

    /**
     * @brief Returns the player's current block.
     * @return Block value.
     */
    int getBlock() const;
};

#endif