/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "../include/CardShop.h"
#include "../include/Game.h"
#include "../include/CardManager.h"

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
    bool inShop = true;
    while (inShop)
    {
        std::cout << "\033c"; // Clear screen (Unix)
        printShopArt(state);
        int choice = getShopChoice();
        handleChoice(choice, state, inShop);
    }
    state.last_message = "Left the card shop";
}

/**
 * @brief Displays the shop UI.
 * @param state Current player resources and deck.
 */
void CardShop::printShopArt(const GameState& state) const
{
    std::cout << "\n=== TOY CARD SHOP ===\n"
              << "Gold: " << state.inventory.gold
              << "  Wood: " << state.inventory.wood
              << "  Stone: " << state.inventory.stone << "\n\n";

    for (size_t i = 0; i < packs.size(); ++i)
    {
        std::cout << i + 1 << ". " << packs[i].name << " ("
                  << packs[i].gold_cost << "G, " << packs[i].wood_cost << "W, "
                  << packs[i].stone_cost << "S)\n";
    }
    std::cout << "4. Exit\n";
}

/**
 * @brief Validates player input (1-4).
 */
int CardShop::getShopChoice() const
{
    std::string input;
    while (true)
    {
        std::cout << "Choice: ";
        std::getline(std::cin, input);
        try
        {
            int c = std::stoi(input);
            if (c >= 1 && c <= 4) return c;
        }
        catch (...) {}
        std::cout << "Invalid choice!\n";
    }
}

/**
 * @brief Handles purchasing a pack or exiting.
 * @param choice Player's selected option.
 * @param state GameState to modify.
 * @param inShop Loop control flag.
 */
void CardShop::handleChoice(int choice, GameState& state, bool& inShop)
{
    if (choice == 4)
    {
        inShop = false;
        return;
    }

    const CardPack& pack = packs[choice - 1];
    if (state.inventory.gold >= pack.gold_cost &&
            state.inventory.wood >= pack.wood_cost &&
            state.inventory.stone >= pack.stone_cost)
    {
        // Deduct resources
        state.inventory.gold -= pack.gold_cost;
        state.inventory.wood -= pack.wood_cost;
        state.inventory.stone -= pack.stone_cost;

        // Animation and card draw
        std::cout << "\033c";
        std::cout << "Opening pack...\n";
        usleep(500000);
        std::cout << "BOOM!\n";
        usleep(500000);

        std::string card = getRandomCard(pack);
        state.deck_cards.push_back(card);

        // Display result
        std::cout << "\033c";
        std::cout << CardManager::getColor(card)
                  << "You got: " << card << "!\033[0m\n"
                  << "Effect: " << CardManager::getDescription(card) << "\n"
                  << "\nPress ENTER...";
        std::string tmp;
        std::getline(std::cin, tmp);

        // Handle deck limits
        bool cardAdded = false;
        if (state.current_deck.size() >= 15)
        {
            std::cout << "\033c";
            std::cout << "Deck is full! Choose card to replace:\n";
            for (size_t i = 0; i < state.current_deck.size(); ++i)
            {
                std::cout << i + 1 << ". " << CardManager::getColor(state.current_deck[i])
                          << state.current_deck[i] << "\033[0m" << " --- "
                          << CardManager::getDescription(state.current_deck[i]) << "\n";
            }
            int replaceIndex = getShopChoice(1, state.current_deck.size()) - 1;
            state.current_deck[replaceIndex] = card;
        }
        else
        {
            state.current_deck.push_back(card);
            cardAdded = true;
        }

        std::cout << (cardAdded ? "Card added to your deck!\n" : "Card added to collection but not to deck\n");
        inShop = false;
    }
    else
    {
        state.last_message = "Not enough resources!";
        inShop = false;
    }
}

/**
 * @brief Validates input within a custom range.
 */
int CardShop::getShopChoice(int min, int max) const
{
    std::string input;
    while (true)
    {
        std::cout << "Enter choice (" << min << "-" << max << "): ";
        std::getline(std::cin, input);
        try
        {
            int choice = std::stoi(input);
            if (choice >= min && choice <= max) return choice;
        }
        catch (...) {}
        std::cout << "Invalid input!\n";
    }
}

/**
 * @brief Selects a card from a pack using weighted randomness.
 */
std::string CardShop::getRandomCard(const CardPack& pack) const
{
    int total = 0;
    for (const auto& c : pack.cards) total += c.second;

    int roll = rand() % total;
    for (const auto& c : pack.cards)
    {
        if (roll < c.second) return c.first;
        roll -= c.second;
    }
    return pack.cards.back().first;
}