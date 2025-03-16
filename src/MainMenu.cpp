/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "MainMenu.h"

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
