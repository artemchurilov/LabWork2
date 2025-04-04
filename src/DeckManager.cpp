/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/DeckManager.h"
#include "../include/InputSystem.h"
#include "../include/CardManager.h"
#include <iostream>


/**
 * @brief Replaces a card in the player's deck at the specified index.
 * @param index Index of the card to replace (0-based).
 */
void DeckManager::replaceCard(GameState& state, int index)
{
    std::cout << "\033c";
    std::cout << "Select new card:\n";
    for(size_t i = 0; i < state.deck_cards.size(); ++i)
    {
        std::cout << i+1 << ". " << state.deck_cards[i] << "\n";
    }

    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;
    if(choice > 0 && choice <= int(state.deck_cards.size()))
    {
        state.current_deck[index] = state.deck_cards[choice-1];
    }
}

/**
 * @brief Displays the current deck of cards.
 * @details Allows inspecting card details (via `showCardDetails`).
 * Controls:
 * - Enter a card number to view details
 * - 'C' to return to the game
 */
void DeckManager::showDeck(const GameState& state)
{
    InputSystem::disableRawMode();
    std::cout << "\033c";

    std::cout << "=== YOUR DECK ===\n";
    for(size_t i = 0; i < state.current_deck.size(); ++i)
    {
        std::string color = CardManager::getColor(state.current_deck[i]);
        std::cout << color << i+1 << ". " << state.current_deck[i]
                  << "\n";
    }

    std::cout << "\033[0m"<<"\nEnter card number to see details or C to return: ";
    std::string input;
    std::getline(std::cin, input);

    if(input == "c" || input == "C")
    {
        InputSystem::enableRawMode();
        return;
    }

    try
    {
        int index = std::stoi(input) - 1;
        if(index >= 0 && index < int(state.current_deck.size()))
        {
            showCardDetails(state, state.current_deck[index]);
        }
    }
    catch(...) {}

    InputSystem::enableRawMode();
}


/**
 * @brief Shows card details: name, description, and color.
 * @param card Name of the card to display.
 */
void DeckManager::showCardDetails(const GameState& state, const std::string& card)
{
    std::cout << "\033c";
    std::string color = CardManager::getColor(card);
    std::cout << color << "=== " << card << " ===\033[0m\n";
    std::cout << CardManager::getDescription(card) << "\n\n";
    std::cout << "Press any key to continue...";
    std::cout << "\n";
    InputSystem::getKey();
    showDeck(state);

}