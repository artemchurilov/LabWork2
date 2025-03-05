/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "GameObject.h"


GameObject::GameObject(int x, int y, bool collidable) : 
x(x), y(y), isCollidable(collidable)
{

};


bool GameObject::isPassable() const
{
    return false;
};
    
int GameObject::getX()
{
    return x;
};
void GameObject::setX(int _x)
{
    x=_x;
}

int GameObject::getY()
{
    return y;
};
void GameObject::setY(int _y)
{
    y=_y;
}

bool GameObject::getCollidable()
{
    return isCollidable;    
};