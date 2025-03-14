
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "BasicAttack.h"
bool BasicAttack::canUse(const CardPlayer& p, const Enemy& e) const 
{ p.isAlive();
    e.isAlive();
    return true; }