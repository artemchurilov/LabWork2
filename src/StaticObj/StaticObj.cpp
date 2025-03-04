/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "StaticObj.h"

StaticObj::StaticObj(int x, int y, bool collidable) : 
GameObject(x, y, collidable)
{
    
};

bool StaticObj::isPassable() const
{
    return false; 
}