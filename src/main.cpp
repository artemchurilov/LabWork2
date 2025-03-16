/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/


#include "Game.h"

int main()
{
    srand(time(NULL));
    Game game;
    game.run();
    return 0;
}