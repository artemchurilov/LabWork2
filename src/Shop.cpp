
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "../include/Shop.h"
#include <iostream>
#include <limits>

/**
 * @brief Handles the interaction loop with the shop.
 * @param state Reference to the GameState to modify (gold, upgrades, messages).
 * @details
 * - Clears the screen and displays the shop UI.
 * - Processes player input for upgrades or exiting.
 * - Updates the game state based on the player's choices.
 * - Exits when the player selects "Leave Shop".
 */
void Shop::interact(GameState& state)
{
    bool inShop = true;
    while(inShop)
    {
        std::cout << "\033c"; // Clear screen (Unix-only command)
        printShopArt(state);

        int choice = getShopChoice();
        switch(choice)
        {
        case 1:
            upgradeSword(state);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 2:
            upgradeShield(state);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 3:
            inShop = false;
            break;
        }
        std::cin.clear();
    }
    state.last_message = "Left the shop";
}

/**
 * @brief Checks if the shop is passable.
 * @return Always false (blocks movement).
 */
bool Shop::isPassable() const
{
    return false;
}

/**
 * @brief Returns the symbol representing the shop.
 * @return '$' character.
 */
char Shop::getSymbol() const
{
    return '$';
}

/**
 * @brief Renders the shop's UI with ASCII art and player stats.
 * @param state Reference to the GameState for current inventory data.
 * @details Displays:
 * - Shop title art.
 * - Current sword and shield levels.
 * - Player's gold.
 * - Available upgrades with costs.
 */
void Shop::printShopArt(const GameState& state) const
{
    std::cout << R"(
      ╔════════════════════════╗
      ║       TOY'S            ║
      ║       ARMORY           ║
      ╚════════════════════════╝
    )" << '\n';

    printSwordArt(state.inventory.sword_level);
    printShieldArt(state.inventory.shield_level);

    std::cout << "\nGold: " << state.inventory.gold << "\n\n"
              << "1. Upgrade Sword (Lvl " << state.inventory.sword_level << ") - 50 gold\n"
              << "2. Upgrade Shield (Lvl " << state.inventory.shield_level << ") - 50 gold\n"
              << "3. Leave Shop\n"
              << "\nNOTE: Enter numbers 1-3, press ENTER to confirm\n";
}

/**
 * @brief Gets and validates the player's menu choice.
 * @return Validated integer choice (1-3).
 * @details
 * - Loops until valid input is provided.
 * - Handles non-numeric input and out-of-range values.
 */
int Shop::getShopChoice() const
{
    std::string input;
    int choice = -1;

    while(true)
    {
        std::cout << "\nEnter choice (1-3): ";
        std::getline(std::cin, input);

        try
        {
            choice = std::stoi(input);
            if(choice >= 1 && choice <= 3)
            {
                return choice;
            }
            std::cout << "Please enter a number between 1-3!\n";
        }
        catch(...)
        {
            std::cout << "Invalid input! Numbers only!\n";
        }
    }
}

/**
 * @brief Displays the current sword level (placeholder for future art).
 * @param level Current sword upgrade level.
 */
void Shop::printSwordArt(int level) const
{
    std::cout << " Sword Level: " << level << "\n";
}

/**
 * @brief Displays the current shield level (placeholder for future art).
 * @param level Current shield upgrade level.
 */
void Shop::printShieldArt(int level) const
{
    std::cout << " Shield Level: " << level << "\n";
}

/**
 * @brief Upgrades the player's sword if they have enough gold.
 * @param state Reference to the GameState to modify.
 * @details
 * - Costs 50 gold.
 * - On success: increases sword level, displays confirmation.
 * - On failure: shows error message.
 */
void Shop::upgradeSword(GameState& state)
{
    if(state.inventory.gold >= 50)
    {
        state.inventory.gold -= 50;
        state.inventory.sword_level++;
        showSuccess("SWORD UPGRADED!", "Press ENTER to continue...");
    }
    else
    {
        showError("Not enough gold!");
    }
}

/**
 * @brief Upgrades the player's shield if they have enough gold.
 * @param state Reference to the GameState to modify.
 * @details
 * - Costs 50 gold.
 * - On success: increases shield level, displays confirmation.
 * - On failure: shows error message.
 */
void Shop::upgradeShield(GameState& state)
{
    if(state.inventory.gold >= 50)
    {
        state.inventory.gold -= 50;
        state.inventory.shield_level++;
        showSuccess("SHIELD UPGRADED!", "Press ENTER to continue...");
    }
    else
    {
        showError("Not enough gold!");
    }
}

/**
 * @brief Displays a success message with a title and description.
 * @param title Header text (e.g., "SWORD UPGRADED!").
 * @param message Additional context (e.g., "Press ENTER...").
 * @note Clears the screen before displaying the message.
 */
void Shop::showSuccess(const std::string& title, const std::string& message) const
{
    std::cout << "\033c"; // Clear screen (Unix-only)
    std::cout << title << "\n" << message;
}

/**
 * @brief Displays an error message.
 * @param message Error description (e.g., "Not enough gold!").
 * @note Clears the screen before displaying the message.
 */
void Shop::showError(const std::string& message) const
{
    std::cout << "\033c"; // Clear screen (Unix-only)
    std::cout << "ERROR: " << message << "\nPress ENTER to continue...";
}