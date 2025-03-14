/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "StaticObj.h"

char StaticObj::getSymbol() const { return symbol; };

StaticObj::StaticObj(char symbol): symbol(symbol) {}