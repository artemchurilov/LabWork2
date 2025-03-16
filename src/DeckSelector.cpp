/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "DeckSelector.h"
#include "Game.h"

DeckSelector::DeckType DeckSelector::show()
{
    enableRawMode();
    int selection = 0;
    while(true)
    {
        system("clear");
        printTitle();
        printOptions(selection);

        char c = getKey();
        if(c == 'w' && selection > 0) selection--;
        if(c == 's' && selection < 2) selection++;
        if(c == '\n') break;
    }
    disableRawMode();
    return static_cast<DeckType>(selection);
}


void DeckSelector::printOptions(int selected)
{
    const std::vector<std::string> options =
    {
        "> Risk Rick (10 Strike, 5 Defend)",
        "> Rick Rick (5 Strike, 5 Defend)",
        "> Shieldy Rick (5 Strike, 10 Defend)"
    };

    for(size_t i = 0; i < options.size(); ++i)
    {
        if(int(i) == selected) std::cout << "\033[1;32m";
        std::cout << options[i] << "\033[0m\n";
    }
}

void DeckSelector::printTitle()
{
    std::cout << "ToyRick" << "\n\n";
}