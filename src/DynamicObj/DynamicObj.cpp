/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "DynamicObj.h"

DynamicObj::DynamicObj(int x, int y, bool collidable):
GameObject(x, y, collidable) 
{

}   

bool DynamicObj::isPassable() const
{
    return true;
};