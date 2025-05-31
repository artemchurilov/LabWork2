/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/DeckManager.h"
#include "../include/InputSystem.h"
#include "../include/CardManager.h"
#include "../include/const.h"
#include <iostream>

void DeckManager::replaceCard(GameState& state, int index)
{
    int selected = 0;
    bool selecting = true;

    while(selecting)
    {
        std::cout << "\033c"; // Очистка экрана
        std::cout << YELLOW << "=== REPLACE CARD IN DECK ===\n" << RESET
                  << "Replacing card: "
                  << CardManager::getColor(state.current_deck[index])
                  << state.current_deck[index] << RESET << "\n\n"
                  << "Select new card:\n";

        for(size_t i = 0; i < state.deck_cards.size(); ++i)
        {
            if(static_cast<int>(i) == selected) std::cout << YELLOW << " > ";
            else std::cout << "   ";

            std::cout << CardManager::getColor(state.deck_cards[i])
                      << state.deck_cards[i] << RESET << "\n";
        }

        char c = InputSystem::getKey();
        switch(c)
        {
        case 'w':
            if(selected > 0) selected--;
            break;
        case 's':
            if(selected < static_cast<int>(state.deck_cards.size()) - 1) selected++;
            break;
        case '\n': // Enter
            state.current_deck[index] = state.deck_cards[selected];
            selecting = false;
            break;
        case 'q':
            selecting = false;
            break;
        }
    }
}

void DeckManager::showDeck( GameState& state)
{
    int selectedIndex = 0;
    bool viewingDeck = true;

    while(viewingDeck)
    {
        std::cout << "\033c"; // Очистка экрана
        std::cout << YELLOW << "=== YOUR DECK ===\n" << RESET
                  << "(Press ENTER to see details, Q to quit)\n\n";

        for(size_t i = 0; i < state.current_deck.size(); ++i)
        {
            std::string card = state.current_deck[i];
            std::string color = CardManager::getColor(card);

            if(static_cast<int>(i) == selectedIndex)
                std::cout << YELLOW << " > " << color << card << RESET << "\n";
            else
                std::cout << "   " << color << card << RESET << "\n";
        }

        char c = InputSystem::getKey();
        switch(c)
        {
        case 'w':
            if(selectedIndex > 0) selectedIndex--;
            break;
        case 's':
            if(selectedIndex < static_cast<int>(state.current_deck.size()) - 1)
                selectedIndex++;
            break;
        case '\n': // Enter
            showCardDetails(state.current_deck[selectedIndex]);
            break;
        case 'q':
            viewingDeck = false;
            break;
        }
    }
}

void DeckManager::showCardDetails(const std::string& card)
{
    bool viewingDetails = true;

    while(viewingDetails)
    {
        std::cout << "\033c"; // Очистка экрана
        std::string color = CardManager::getColor(card);
        std::cout << color << "=== " << card << " ===\033[0m\n";
        std::cout << CardManager::getDescription(card) << "\n\n";
        std::cout << "Press any key to return...";

        InputSystem::getKey();
        viewingDetails = false;
    }
}