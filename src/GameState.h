/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H

struct GameState
{
    struct
    {
        int hp = 100;
        int energy = 50;
        int gold = 0;
        int wood = 0;
        int stone = 0;
    } inventory;

    int day = 1;
};


#endif

