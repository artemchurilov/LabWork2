/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "../include/CardShop.h"
#include "../include/Game.h"
#include "../include/CardManager.h"
#include "../include/InputSystem.h"
#include "../include/const.h"

/**
 * @brief Returns the shop's symbol ('K').
 */
char CardShop::getSymbol() const
{
    return 'K';
}

/**
 * @brief Blocks movement (shop is impassable).
 */
bool CardShop::isPassable() const
{
    return false;
}

/**
 * @brief Manages the shop interaction loop.
 * @details
 * - Clears the screen and displays the shop UI.
 * - Processes player input until they exit.
 * - Updates the GameState with purchased cards.
 */
void CardShop::interact(GameState& state)
{
    inCardShop = true;
    selectedItem = 0;
    message = "";
    inReplaceMode = false;

    while(inCardShop)
    {
        std::cout << "\033c";
        if(inReplaceMode)
        {
            renderReplaceInterface(state);
        }
        else
        {
            renderShopInterface(state);
        }
        handleInput(state);
    }
    state.last_message = "Left the card shop";
};

void CardShop::renderShopInterface(const GameState& state) const
{
    std::cout << "\n" << YELLOW << "=== TOY CARD SHOP ===\n" << RESET
              << "Gold: " << state.inventory.gold
              << "  Wood: " << state.inventory.wood
              << "  Stone: " << state.inventory.stone << "\n\n";

    for(size_t i = 0; i < packs.size(); ++i)
    {
        if(static_cast<int>(i) == selectedItem) std::cout << YELLOW << " > ";
        else std::cout << "   ";

        std::cout << packs[i].name << " ("
                  << packs[i].gold_cost << "G, " << packs[i].wood_cost << "W, "
                  << packs[i].stone_cost << "S)" << RESET << "\n";
    }

    if(selectedItem == static_cast<int>(packs.size())) std::cout << YELLOW << " > ";
    else std::cout << "   ";
    std::cout << "Exit" << RESET << "\n";
}

void CardShop::renderReplaceInterface(const GameState& state) const
{
    std::cout << "\n" << YELLOW << "=== REPLACE CARD IN DECK ===\n" << RESET
              << "Your new card: " << CardManager::getColor(newCard)
              << newCard << RESET << "\n\n"
              << "Select card to replace:\n";

    for(size_t i = 0; i < state.current_deck.size(); ++i)
    {
        if(static_cast<int>(i) == replaceIndex) std::cout << YELLOW << " > ";
        else std::cout << "   ";

        std::cout << CardManager::getColor(state.current_deck[i])
                  << state.current_deck[i] << RESET << " - "
                  << CardManager::getDescription(state.current_deck[i]) << "\n";
    }
}

void CardShop::handleInput(GameState& state)
{
    char c = InputSystem::getKey();
    int totalItems = packs.size() + 1;

    if(inReplaceMode)
    {
        switch(c)
        {
        case 'w':
            replaceIndex = (replaceIndex - 1 + state.current_deck.size()) % state.current_deck.size();
            break;
        case 's':
            replaceIndex = (replaceIndex + 1) % state.current_deck.size();
            break;
        case '\n':
            state.current_deck[replaceIndex] = newCard;
            inCardShop = false;
            break;
        case 'q':
            inCardShop = false;
            break;
        }
    }
    else
    {
        switch(c)
        {
        case 'w':
            selectedItem = (selectedItem - 1 + totalItems) % totalItems;
            break;
        case 's':
            selectedItem = (selectedItem + 1) % totalItems;
            break;
        case '\n':
            if(selectedItem == static_cast<int>(packs.size()))
            {
                inCardShop = false;
            }
            else
            {
                const CardPack& pack = packs[selectedItem];
                if(state.inventory.gold >= pack.gold_cost &&
                        state.inventory.wood >= pack.wood_cost &&
                        state.inventory.stone >= pack.stone_cost)
                {

                    state.inventory.gold -= pack.gold_cost;
                    state.inventory.wood -= pack.wood_cost;
                    state.inventory.stone -= pack.stone_cost;

                    newCard = getRandomCard(pack);
                    state.deck_cards.push_back(newCard);

                    std::cout << "\033c";
                    std::cout << "Opening pack...\n";
                    usleep(500000);
                    std::cout << "BOOM!\n";
                    usleep(500000);

                    std::cout << "\033c";
                    std::cout << CardManager::getColor(newCard)
                              << "You got: " << newCard << "!\033[0m\n"
                              << "Effect: " << CardManager::getDescription(newCard) << "\n"
                              << "\nPress any key...";
                    InputSystem::getKey();
                    if(state.current_deck.size() >= 15)
                    {
                        inReplaceMode = true;
                        replaceIndex = 0;
                    }
                    else
                    {
                        state.current_deck.push_back(newCard);
                        inCardShop = false;
                    }
                }
                else
                {
                    message = "Not enough resources!";
                }
            }
            break;
        case 'q':
            inCardShop = false;
            break;
        }
    }
}

std::string CardShop::getRandomCard(const CardPack& pack) const
{
    int total = 0;
    for(const auto& c : pack.cards) total += c.second;

    int roll = rand() % total;
    for(const auto& c : pack.cards)
    {
        if(roll < c.second) return c.first;
        roll -= c.second;
    }
    return pack.cards.back().first;
}