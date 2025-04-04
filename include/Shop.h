/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef SHOP_H
#define SHOP_H

#include "GameObject.h"

/**
 * @class Shop
 * @brief Represents a shop where players can upgrade their sword and shield.
 * @details Inherits from GameObject and blocks movement. Interaction triggers a menu-driven UI.
 */
class Shop : public GameObject
{
public:
    /**
     * @override
     * @brief Returns the shop's symbol.
     * @return '$' (ASCII character).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Checks if the shop can be traversed.
     * @return Always false (blocks movement).
     */
    bool isPassable() const override;

    /**
     * @brief Displays ASCII art for the shield's current level.
     * @param level Current shield level.
     */
    void printShieldArt(int level) const;

    /**
     * @brief Displays ASCII art for the sword's current level.
     * @param level Current sword level.
     */
    void printSwordArt(int level) const;

    /**
     * @brief Upgrades the player's sword if they have enough gold (50).
     * @param state GameState to modify (gold, sword level, messages).
     */
    void upgradeSword(GameState& state);

    /**
     * @brief Upgrades the player's shield if they have enough gold (50).
     * @param state GameState to modify (gold, shield level, messages).
     */
    void upgradeShield(GameState& state);

    /**
     * @brief Displays a success message with a title and text.
     * @param title Header text (e.g., "SWORD UPGRADED!").
     * @param message Additional context (e.g., "Press ENTER...").
     */
    void showSuccess(const std::string& title, const std::string& message) const;

    /**
     * @brief Displays an error message (e.g., "Not enough gold!").
     * @param message Error text to display.
     */
    void showError(const std::string& message) const;

    /**
     * @override
     * @brief Enters the shop menu loop.
     * @param state GameState to modify during interaction.
     */
    void interact(GameState& state) override;

    /**
     * @brief Renders the shop UI, including sword/shield levels and gold.
     * @param state GameState for current player stats.
     */
    void printShopArt(const GameState& state) const;

    /**
     * @brief Gets the player's menu choice (1-3).
     * @return Selected option (1: upgrade sword, 2: upgrade shield, 3: leave).
     */
    int getShopChoice() const;
};

#endif
