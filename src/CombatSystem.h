/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H
#include "CardPlayer.h"
#include "Enemy.h"
#include <limits>

class CombatSystem
{
    CardPlayer player;
    Enemy enemy;
    int turnNumber = 0;

public:

    void clearInput();

    void printHand();
    bool startCombat();
};

#endif