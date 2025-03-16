#include "CardManager.h"
#include <map>

std::string CardManager::getColor(const std::string& cardName) {
            if (cardName.find("Ultra") != std::string::npos) return "\033[33m";
            if (cardName.find("Punch") != std::string::npos || 
                cardName.find("Kick") != std::string::npos || 
                cardName.find("Strike") != std::string::npos) return "\033[31m";
            if (cardName.find("Heal") != std::string::npos) return "\033[32m";
            if (cardName.find("Block") != std::string::npos|| 
            cardName.find("Defend") != std::string::npos) return "\033[37m";
            
            return "\033[0m";
        }
    
     std::string CardManager::getDescription(const std::string& cardName) {
            static std::map<std::string, std::string> descriptions = {
                {"Strike", "Deal 6 damage (Cost: 1)"},
                {"Defend", "Gain 5 block (Cost: 1)"},
                {"Fist Punch", "Deal 12 damage (Cost: 1)"},

            };
            return descriptions.count(cardName) ? descriptions[cardName] : "Unknown card";
        }
