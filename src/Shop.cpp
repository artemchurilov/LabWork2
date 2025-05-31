/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Shop.h"
#include "../include/InputSystem.h"
#include <iostream>
#include "../include/const.h"

void Shop::interact(GameState& state)
{
    inShop = true;
    while(inShop)
    {
        renderShopInterface(state);
        handleShopInput(state);
    }
}

void Shop::renderShopInterface(const GameState& state)
{
    std::cout << "\033c";

    std::cout << R"(
╔═══════════════════════════════════╗
║           BLACKSMITH'S            ║
╠═══════════════════════════════════╣


)";
    
    const std::vector<std::string> items = 
    {
        "   1. Sword Upgrade - 50g",
        "   2. Shield Upgrade - 50g",
        "   3. Exit"
    };
    
    for(size_t i = 0; i < items.size(); ++i) {
        if(int(i) == selectedItem) std::cout<< YELLOW << " > ";
        else std::cout << "   ";
        std::cout << items[i] << RESET<<"\n";
    }
    
    std::cout << "\nGold: " << state.inventory.gold << "\n";
    std::cout << "Current sword level: " << state.inventory.sword_level << "\n";
    std::cout << "Current shield level: " << state.inventory.shield_level << "\n";
}

void Shop::handleShopInput(GameState& state) {
    char c = InputSystem::getKey();
    switch(c) {
        case 'w': 
            selectedItem = (selectedItem - 1 + 3) % 3;
            break;
        case 's':
            selectedItem = (selectedItem + 1) % 3;
            break;
        case '\n':
            switch(selectedItem) {
                case 0:
                    if(state.inventory.gold >= 50) {
                        state.inventory.gold -= 50;
                        state.inventory.sword_level++;
                    }
                    break;
                case 1:
                    if(state.inventory.gold >= 50) {
                        state.inventory.gold -= 50;
                        state.inventory.shield_level++;
                    }
                    break;
                case 2:
                    inShop = false;
                    break;
            }
            break;
        case 'q':
            inShop = false;
            break;
    }
}