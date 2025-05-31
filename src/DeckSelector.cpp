/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/DeckSelector.h"
#include "../include/Game.h"

/**
 * @brief Renders the interactive deck selection screen.
 * @details
 * - Enables raw terminal input for single-key navigation.
 * - Uses `w`/`s` keys to cycle options and `Enter` to confirm.
 * - Returns the selected deck type.
 */
DeckSelector::DeckType DeckSelector::show()
{
    InputSystem::enableRawMode();
    int selection = 0;
    while(true)
    {
        system("clear"); // Unix-only (use "cls" on Windows)
        printTitle();
        printOptions(selection);

        char c = InputSystem::getKey(); // Implemented elsewhere
        if(c == 'w' && selection > 0) selection--;
        if(c == 's' && selection < 2) selection++;
        if(c == '\n') break;
    }
    return static_cast<DeckType>(selection);
}

/**
 * @brief Prints deck options with ANSI color highlighting.
 * @param selected Index of the highlighted option.
 */
void DeckSelector::printOptions(int selected)
{
    const std::vector<std::string> options =
    {
        "> Rick (5 Strike, 5 Defend)",
        "> Risk Rick (10 Strike, 5 Defend)",
        "> Shieldy Rick (5 Strike, 10 Defend)"
    };

    for(size_t i = 0; i < options.size(); ++i)
    {
        if(int(i) == selected)
            std::cout << "\033[1;32m"; // Green highlight
        std::cout << options[i] << "\033[0m\n";
    }
}

/**
 * @brief Prints the "ToyRick" title.
 */
void DeckSelector::printTitle()
{
    std::cout << "ToyRick" << "\n\n";
}

/**
 * @brief Initializes the starting deck based on the player's choice.
 * @details Available decks:
 * - RISK_RICK: 15 cards (10 attacks, 5 defends)
 * - SHIELDY_RICK: 15 cards (5 attacks, 10 defends)
 * - RICK : 10 cards (5 attacks, 5 defends)
 */

void DeckSelector::selectDeck(GameState& state)
{

    DeckSelector selector;
    auto deckType = selector.show();

    switch(deckType)
    {
    case DeckSelector::RICK:
        state.current_deck = {"Strike","Strike","Strike","Strike","Strike",
                              "Defend","Defend","Defend","Defend","Defend"
                             };

        break;
    case DeckSelector::RISK_RICK:
        state.current_deck = {"Strike","Strike","Strike","Strike","Strike",
                              "Strike","Strike","Strike","Strike","Strike",
                              "Defend","Defend","Defend","Defend","Defend"
                             };
        break;

    case DeckSelector::SHIELDY_RICK:
        state.current_deck = {"Strike","Strike","Strike","Strike","Strike",
                              "Defend","Defend","Defend","Defend","Defend",
                              "Defend","Defend","Defend","Defend","Defend"
                             };
        break;
    }
}