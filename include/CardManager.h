/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "Card.h"
#include <string>

/**
 * @class CardManager
 * @brief Provides metadata for cards (colors and descriptions).
 * @details Uses static methods to retrieve card colors and descriptions by name.
 */
class CardManager
{
public:
    /**
     * @brief Returns the ANSI color code for a card based on its name.
     * @param cardName Name of the card (e.g., "Ultra Duper Punch").
     * @return ANSI escape code for the color:
     * - Yellow (`\033[33m`) for cards containing "Ultra".
     * - Red (`\033[31m`) for attack cards ("Punch", "Kick", "Strike").
     * - Green (`\033[32m`) for healing cards ("Heal").
     * - White (`\033[37m`) for block cards ("Block", "Defend").
     * - Reset color (`\033[0m`) for unknown types.
     */
    static std::string getColor(const std::string& cardName);

    /**
     * @brief Returns the description of a card by name.
     * @param cardName Name of the card (e.g., "Strike").
     * @return Predefined description or "Unknown card" if not found.
     */
    static std::string getDescription(const std::string& cardName);
};

#endif