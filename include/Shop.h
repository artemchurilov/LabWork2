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
     * @brief Main interaction method for the shop
     * @param state Current game state containing player inventory
     * 
     * @details
     * - Initializes shop state variables
     * - Enters shop interaction loop
     * - Renders interface and processes input
     * - Updates player equipment on purchases
     */
    void interact(GameState& state) override;
    
    /**
     * @brief Checks if shop is passable
     * @return false - shop blocks player movement
     */
    bool isPassable() const override { return false; }
    
    /**
     * @brief Gets map symbol for shop
     * @return 'S' character symbol
     */
    char getSymbol() const override { return 'S'; }

private:
    /**
     * @brief Renders shop interface
     * @param state Current game state for displaying resources
     * 
     * @details
     * - Shows available upgrades with costs
     * - Displays current equipment levels
     * - Highlights selected item
     * - Shows player's gold
     */
    void renderShopInterface(const GameState& state);
    
    /**
     * @brief Handles keyboard input for shop navigation
     * @param state Current game state to modify
     * 
     * @details
     * - Processes:
     *   - 'w'/'s': Navigate up/down
     *   - Enter: Confirm selection
     *   - 'q': Exit shop
     * - Deducts gold for purchases
     * - Upgrades player equipment
     */
    void handleShopInput(GameState& state);
    
    int selectedItem = 0;     ///< Currently selected menu item
    bool inShop = false;      ///< Flag indicating active shop session
};

#endif
