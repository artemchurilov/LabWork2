/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "DynamicObj.h"
#include "Inventory.h"

class Player : public DynamicObj {
    public:
        Player();
        Inventory inventory;
    };
    
#endif