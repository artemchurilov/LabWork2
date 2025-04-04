/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/CardManager.h"
#include <map>

#include "../include/const.h"
/**
 * @brief Maps card names to their ANSI color codes based on keywords.
 * @param cardName Name of the card to check.
 * @return ANSI color code as a string.
 */
std::string CardManager::getColor(const std::string& cardName)
{
    if (cardName.find("Ultra") != std::string::npos) return YELLOW;
    if (cardName.find("Punch") != std::string::npos ||
            cardName.find("Kick") != std::string::npos ||
            cardName.find("Strike") != std::string::npos) return RED;
    if (cardName.find("Heal") != std::string::npos) return GREEN;
    if (cardName.find("Block") != std::string::npos ||
            cardName.find("Defend") != std::string::npos) return GREY;
    return RESET;
}

/**
 * @brief Retrieves card descriptions from a predefined map.
 * @param cardName Name of the card to look up.
 * @return Description or "Unknown card" if not found.
 * @details Predefined cards:
 * - "Strike": "Deal 6 damage (Cost: 1)"
 * - "Defend": "Gain 5 block (Cost: 1)"
 * - "Fist Punch": "Deal 12 damage (Cost: 1)"
 * - ... (other cards)
 */
std::string CardManager::getDescription(const std::string& cardName)
{
    static std::map<std::string, std::string> descriptions =
    {
        {"Strike", "Deal 6 damage (Cost: 1)"},
        {"Defend", "Gain 5 block (Cost: 1)"},
        {"Fist Punch", "Deal 12 damage (Cost: 1)"},
        {"Fist Block", "Gain 8 block (Cost: 1)"},
        {"Arm Heal", "Restore 9 HP (Cost: 1)"},
        {"Arm Combo", "Deal 6 damage and gain 5 block (Cost: 1)"},
        {"Ultra Duper Punch", "Deal 100 damage (Cost: 1)"},
        {"Foot Kick", "Deal 8 damage (Cost: 1)"},
        {"Leg Block", "Gain 12 block (Cost: 1)"},
        {"Leg Heal", "Restore 8 HP (Cost: 1)"},
        {"Leg Combo", "Deal 5 damage and gain 6 block (Cost: 1)"},
        {"Ultra Duper Kick", "Gain 100 block (Cost: 1)"},
        {"ArmDiscard", "Take 3 damage, gain 2 energy (Cost: 1)"},
        {"AutoRepair", "Restore 15 HP"},
        {"Strongest Spell", "Instant death"},
        {"Clink-clock", "Do nothing"}
    };
    return descriptions.count(cardName) ? descriptions[cardName] : "Unknown card";
}