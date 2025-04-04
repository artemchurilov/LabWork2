#include "player/player.h"
#include <iostream>
#include "menu/menu.h"
#include "battlefield/battlefield.h"
#include "obj/obj.h"

int main() {
    startMenu();
    std::cout<<std::endl;
    Battlefield bg1(5, 5);

    Obj obj1(0,0,1,1);

    bg1.addObject(0,0,&obj1);

    bg1.printBattlefield();

    return 0;
};
