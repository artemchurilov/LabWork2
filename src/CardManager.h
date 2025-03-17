

#ifndef CARDMANAGER_H
#define CARDMANAGER_H
#include "Card.h"
#include <iostream>
#include <map>

class CardManager
{
public:
    static std::string getColor(const std::string& cardName)
    {
        if (cardName.find("Ultra") != std::string::npos) return "\033[33m";
        if (cardName.find("Punch") != std::string::npos ||
                cardName.find("Kick") != std::string::npos ||
                cardName.find("Strike") != std::string::npos) return "\033[31m";
        if (cardName.find("Heal") != std::string::npos) return "\033[32m";
        if (cardName.find("Block") != std::string::npos||
                cardName.find("Defend") != std::string::npos) return "\033[37m";
    
        return "\033[0m";
    }
    static std::string getDescription(const std::string& cardName)
    {
        static std::map<std::string, std::string> descriptions =
        {
            {"Strike", "Deal 6 damage (Cost: 1)"},
            {"Defend", "Gain 5 block (Cost: 1)"},
            {"Fist Punch", "Deal 12 damage (Cost: 1)"},
            {"Fist Block", "Gain 8 damage (Cost: 1)"},
            {"Arm Heal", "Restore 10 HP (Cost: 1)"},
            {"Arm Combo", "Deal 6 damage and gain 5 block (Cost: 1)"},
            {"Ultra Duper Punch", "Deal 100 damage (Cost: 1)"},
            {"Foot Kick", "Deal 8 damage (Cost: 1)"},
            {"Leg Block", "Gain 12 block (Cost: 1)"},
            {"Leg Heal", "Restore 9 HP (Cost: 1)"},
            {"Leg Combo", "Deal 5 damage and gain 6 block (Cost: 1)"},
            {"Ultra Duper Kick","Deal 100 damage (Cost:1)"},
            {"ArmDiscard", "Take 3 damage, gain 2 energy (Cost:1)"},
            {"AutoRepair","Heal 6 per card played"},
            {"Strongest Spell","Instant death"},
            {"Clink-clock","Do nothing"},
        };
        return descriptions.count(cardName) ? descriptions[cardName] : "Unknown card";
    };
};

#endif