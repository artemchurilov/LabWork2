#include "CardShop.h"
#include "Game.h"
#include "CardManager.h"

char CardShop::getSymbol() const
{
    return 'K';
}
bool CardShop::isPassable() const
{
    return false;
}

void CardShop::interact(GameState& state)
{
    bool inShop = true;
    while(inShop)
    {
        system("clear");
        printShopArt(state);
        int choice = getShopChoice();
        handleChoice(choice, state, inShop);
    }
    state.last_message = "Left the card shop";
}

void CardShop::printShopArt(const GameState& state) const
{
    std::cout << "\n=== TOY CARD SHOP ===\n";
    std::cout << "Gold: " << state.inventory.gold
              << "  Wood: " << state.inventory.wood
              << "  Stone: " << state.inventory.stone << "\n\n";

    for(size_t i = 0; i < packs.size(); ++i)
    {
        std::cout << i+1 << ". " << packs[i].name << " ("
                  << packs[i].gold_cost << "G, " << packs[i].wood_cost << "W, "
                  << packs[i].stone_cost << "S)\n";
    }
    std::cout << "4. Exit\n";
}

int CardShop::getShopChoice() const
{
    std::string input;
    while(true)
    {
        std::cout << "Choice: ";
        std::getline(std::cin, input);
        try
        {
            int c = std::stoi(input);
            if(c >= 1 && c <= 4) return c;
        }
        catch(...) {}
        std::cout << "Invalid choice!\n";
    }
}

void CardShop::handleChoice(int choice, GameState& state, bool& inShop)
{
    if(choice == 4)
    {
        inShop = false;
        return;
    }

    const CardPack& pack = packs[choice-1];
    if(state.inventory.gold >= pack.gold_cost &&
            state.inventory.wood >= pack.wood_cost &&
            state.inventory.stone >= pack.stone_cost)
    {
        state.inventory.gold -= pack.gold_cost;
        state.inventory.wood -= pack.wood_cost;
        state.inventory.stone -= pack.stone_cost;

        system("clear");
        std::cout << "Opening pack...\n";
        usleep(500000);
        std::cout << "BOOM!\n";
        usleep(500000);

        std::string card = getRandomCard(pack);
        state.deck_cards.push_back(card);

        system("clear");
        std::cout << CardManager::getColor(card)
                  << "You got: " << card << "!\033[0m\n";
        std::cout << "Effect: " << CardManager::getDescription(card) << "\n";
        std::cout << "\nPress ENTER...";


        std::string tmp;
        std::getline(std::cin, tmp);
        bool cardAdded = false;
        if(state.current_deck.size() >= 15)
        {
            system("clear");
            std::cout << "Deck is full! Choose card to replace:\n";
            for(size_t i = 0; i < state.current_deck.size(); ++i)
            {
                std::cout << i+1 << ". " << state.current_deck[i] << "\n";
            }

            int replaceIndex = getShopChoice(1, state.current_deck.size()) - 1;
            state.current_deck[replaceIndex] = card;
        }
        else
        {
            state.current_deck.push_back(card);
            cardAdded = true;
        }

        if(cardAdded)
        {
            std::cout << "Card added to your deck!\n";
        }
        else
        {
            std::cout << "Card added to collection but not to deck\n";
        }
        inShop = false;
    }
    else
    {
        state.last_message = "Not enough resources!";
        inShop = false;
    }
}
int CardShop::getShopChoice(int min, int max) const
{
    std::string input;
    while(true)
    {
        std::cout << "Enter choice (" << min << "-" << max << "): ";
        std::getline(std::cin, input);
        try
        {
            int choice = std::stoi(input);
            if(choice >= min && choice <= max) return choice;
        }
        catch(...) {}
        std::cout << "Invalid input!\n";
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

void CardShop::printCardDescription(const std::string& card) const
{
    if(card == "Fist Punch") std::cout << "Deal 12 damage";
    else if(card == "Fist Block") std::cout << "Gain 8 block";
    else if(card == "Arm Heal") std::cout << "Restore 10 HP";
    else if(card == "Arm Combo") std::cout << "6 damage + 6 block";
    else if(card == "Ultra Duper Punch") std::cout << "Deal 100 damage";
    else if(card == "Foot Kick") std::cout << "Deal 12 damage";
    else if(card == "Leg Block") std::cout << "Gain 8 block";
    else if(card == "Leg Heal") std::cout << "Restore 10 HP";
    else if(card == "Leg Combo") std::cout << "6 damage + 6 block";
    else if(card == "Ultra Duper Kick") std::cout << "Deal 100 damage";
    else if(card == "ArmDiscard") std::cout << "Take 3 damage, gain 2 energy";
    else if(card == "AutoRepair") std::cout << "Heal 6 per card played";
    else if(card == "Unluck") std::cout << "Instant death";
    else if(card == "Clink-clock") std::cout << "Do nothing";
}
