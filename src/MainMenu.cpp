/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/MainMenu.h"
#include "../include/const.h"
#include "../include/DeckSelector.h"

void MainMenu::printTitle()
{
    std::cout << "ToyRick" << "\n\n";
}



void MainMenu::printOptions(int selected)
{
    const std::vector<std::string> options =
    {
        "> Start Game",
        "> Rules",
        "> Quit"
    };

    for(int i = 0; i < int(options.size()); ++i)
    {
        if(i == selected) std::cout << "\033[1;32m";
        std::cout << options[i] << "\033[0m\n";
    }
}

/**
 * @brief Displays the main menu and handles player choices.
 * @details The loop continues until "Quit" or "Start" is selected.
 * - Calls `selectDeck()` if "Start" is chosen.
 * - Shows the rules screen if "Rules" is selected.
 * - Stops the game if "Quit" is selected.
 */

bool MainMenu::showMainMenu(GameState& state, bool& running)
{
    MainMenu menu;
    while(true)
    {
        MenuResult result = menu.show();
        switch(result)
        {
        case MainMenu::START:
            DeckSelector selector;
            selector.selectDeck(state);
            return true;
        case MainMenu::RULES:
            showRulesScreen();
            break;
        case MainMenu::QUIT:
            running = false;
            return false;
        }
    }
}
void MainMenu::showRulesScreen()
{
    std::cout << "\033c";
    std::cout << YELLOW << "\n📜 " << RESET << "GAME RULES & CONTROLS" << YELLOW << " 📜\n" << RESET;
    std::cout << "--------------------------------------------------\n";

    std::cout << YELLOW << "\n🎮 CONTROLS:\n" << RESET;
    std::cout << "- " << GREEN << "W, A, S, D" << RESET << " - Movement:\n";
    std::cout << "- " << GREEN << "B" << RESET << " - Toggle Map\n";
    std::cout << "- " << GREEN << "C" << RESET << " - View Card Deck\n";
    std::cout << "- " << GREEN << "Q" << RESET << " - Quit Game\n";

    std::cout << YELLOW << "\n🌳 RESOURCES & OBJECTS:\n" << RESET;
    std::cout << "- " << GREEN << "T (Tree)" << RESET << "   - Source of " << GREEN << "Wood\n" << RESET;
    std::cout << "- " << GREEN << "S (Stone)" << RESET << "  - Source of " << GREEN << "Stone\n" << RESET;
    std::cout << "- " << GREEN << "M (Mob)" << RESET << "    - Drops " << GREEN << "Gold\n" << RESET;
    std::cout << "- " << GREEN << "C (Campfire)" << RESET << " - Restores " << GREEN << "HP/Energy\n" << RESET;
    std::cout << "- " << GREEN << "$ (Shop)" << RESET << " - Source of new " << GREEN << "Upgrades\n" << RESET;
    std::cout << "- " << GREEN << "K (CardShop)" << RESET << " - Source of new " << GREEN << "Cards\n" << RESET;
    std::cout << "- " << GREEN << "B (Boss)" << RESET << " - The Final " << GREEN << "Challenge\n" << RESET;


    std::cout << "\n" << RED << "TIP: " << RESET << "Type " << GREEN << "Q" << RESET
              << " anytime to quit the game!\n\n";
    InputSystem::getKey();
}