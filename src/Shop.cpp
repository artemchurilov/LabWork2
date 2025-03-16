
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Shop.h"
#include <iostream>
#include <limits>

void Shop::interact(GameState& state)
{
    bool inShop = true;
        while(inShop) {
            system("clear");
            printShopArt(state);
            
            int choice = getShopChoice();
            
            switch(choice) {
                case 1: upgradeSword(state); break;
                case 2: upgradeShield(state); break;
                case 3: inShop = false; break;
                default: showError("Invalid choice!");
            }
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        state.last_message = "Left the shop";
};

bool Shop::isPassable() const
{
    return false;
}

char Shop::getSymbol() const
{
    return '$';
}


void Shop::printShopArt(const GameState& state) const {
    std::cout << R"(
      ╔════════════════════════╗
      ║       TOY'S            ║
      ║       ARMORY           ║
      ╚════════════════════════╝
    )" << '\n';
    
    printSwordArt(state.inventory.sword_level);
    printShieldArt(state.inventory.shield_level);
    
    std::cout << "\nGold: " << state.inventory.gold << "\n\n";
    std::cout << "1. Upgrade Sword (Lvl " << state.inventory.sword_level << ") - 50 gold\n";
    std::cout << "2. Upgrade Shield (Lvl " << state.inventory.shield_level << ") - 50 gold\n";
    std::cout << "3. Leave Shop\n";
    std::cout << "\nNOTE: Enter numbers 1-3, press ENTER to confirm\n";
}

int Shop::getShopChoice() const {
    std::string input;
    int choice = -1;
    
    while(true) {
        std::cout << "\nEnter choice (1-3): ";
        std::getline(std::cin, input);
        
        try {
            choice = std::stoi(input);
            if(choice >= 1 && choice <= 3) return choice;
            std::cout << "Please enter number between 1-3!\n";
        } catch(...) {
            std::cout << "Invalid input! Numbers only!\n";
        }
    }
}


void Shop::printSwordArt(int level) const {
    std::cout << " Sword Level: " << level << "\n";
}


void Shop::printShieldArt(int level) const {
    std::cout << " Shield Level: " << level << "\n";
}

void Shop::upgradeSword(GameState& state) {
    if(state.inventory.gold >= 50) {
        state.inventory.gold -= 50;
        state.inventory.sword_level++;
        showSuccess("SWORD UPGRADED!", "Press ENTER to continue...");
    } else {
        showError("Not enough gold!");
    }
}

void Shop::upgradeShield(GameState& state) {
    if(state.inventory.gold >= 50) {
        state.inventory.gold -= 50;
        state.inventory.shield_level++;
        showSuccess("SHIELD UPGRADED!", "Press ENTER to continue...");
    } else {
        showError("Not enough gold!");
    }
}

void Shop::showSuccess(const std::string& title, const std::string& message) const {
    system("clear");
    std::cout << title << "\n" << message;
    std::string tmp;
    std::getline(std::cin, tmp);
}

void Shop::showError(const std::string& message) const {
    system("clear");
    std::cout << "ERROR: " << message << "\nPress TWICE ENTER to continue...";
    std::string tmp;
    std::getline(std::cin, tmp);
}