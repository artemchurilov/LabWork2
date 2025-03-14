/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "DynamicObj.h"

char DynamicObj::getSymbol() const 
{ 
    return symbol; 
}

DynamicObj::DynamicObj(char symbol): symbol(symbol) {}