#include "CardShop.h"

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
    std::cout << R"(
                  ╔════════════════════════╗
                  ║   TOY CARD SHOP        ║
                  ╚════════════════════════╝
                )" << '\n';

    std::cout << "Your Resources:\n";
    std::cout << "Gold: " << state.inventory.gold
              << " Wood: " << state.inventory.wood
              << " Stone: " << state.inventory.stone << "\n\n";

    for(size_t i = 0; i < packs.size(); ++i)
    {
        std::cout << i+1 << ". " << packs[i].name << " Pack\n"
                  << "   " << packs[i].card_name
                  << " (Cost: " << packs[i].gold_cost << "G";
        if(packs[i].wood_cost > 0) std::cout << ", " << packs[i].wood_cost << "W";
        if(packs[i].stone_cost > 0) std::cout << ", " << packs[i].stone_cost << "S";
        std::cout << ")\n";
    }
    std::cout << "\n4. Leave Shop\n";
}

int CardShop::getShopChoice() const
{
    std::string input;
    while(true)
    {
        std::cout << "\nChoose pack (1-3) or 4 to leave: ";
        std::getline(std::cin, input);
        try
        {
            int choice = std::stoi(input);
            if(choice >= 1 && choice <= 4) return choice;
        }
        catch(...) {}
        std::cout << "Invalid input! Enter 1-4\n";
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
        state.cards.push_back(pack.card_name);
        state.last_message = "Bought " + pack.card_name + " card!";
        inShop = false;
    }
    else
    {
        state.last_message = "Not enough resources!";
        inShop = false;
    }

};