
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Shop.h"
#include <iostream>
#include <limits>

void Shop::interact(GameState& state)
{
    showShopInterface(state);
};
bool Shop::isPassable() const
{
    return false;
}

char Shop::getSymbol() const
{
    return '$';
}

void Shop::printSnakeArt()
{
    std::cout << "\n"<<">---4~~~~~~~~~~-";
};

void Shop::showShopInterface(GameState& state)
{
    system("clear");
    printSnakeArt();
    std::cout << "\n=== SNEK'S SHOP ===";
    std::cout << "\n1. Upgrade sword (Current: " << state.inventory.sword_level << ") - 50 gold";
    std::cout << "\n2. Upgrade shield (Current: " << state.inventory.shield_level << ") - 50 gold";
    std::cout << "\n3. Leave shop";

    int choice;
    std::cout << "\nYour choice: ";
    std::cin >> choice;

    if(choice == 1)
    {
        if(state.inventory.gold >= 50)
        {
            state.inventory.gold -= 50;
            state.inventory.sword_level++;
            state.last_message = "Sword upgraded to level " + std::to_string(state.inventory.sword_level);
        }
        else
        {
            state.last_message = "Not enough gold!";
        }
    }
    else if(choice == 2)
    {
        if(state.inventory.gold >= 50)
        {
            state.inventory.gold -= 50;
            state.inventory.shield_level++;
            state.last_message = "Shield upgraded to level " + std::to_string(state.inventory.shield_level);
        }
        else
        {
            state.last_message = "Not enough gold!";
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};