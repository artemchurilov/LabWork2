/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DYNAMICOBJ_H
#define DYNAMICOBJ_H

#include "../GameObject/GameObject.h"

class DynamicObj : public GameObject 
{
public:
    DynamicObj(int x, int y, bool collidable);  
    bool isPassable() const override;
    virtual void move(int dx, int dy) 
    {
        x += dx;
        y += dy;
    }
};

#endif
