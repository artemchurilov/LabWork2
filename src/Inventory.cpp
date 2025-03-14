/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Inventory.h"
#include <iostream>

void Inventory::print() const
{
    std::cout << "HP: " << hp << "\n"
              << "Energy: " << energy << "\n"
              << "Gold: " << gold << "\n"
              << "Wood: " << wood << "\n"
              << "Stone: " << stone << std::endl;
}