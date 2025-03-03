/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include "entity.h"

//конструкторыяИдеструкторы
Entity::Entity(int new_posX, int new_posY,float new_movespeed, int new_counterHP):Obj(new_posX, new_posY,true,true), movespeed(new_movespeed), counterHP(new_counterHP)
{
    
};
Entity::~Entity()
{

};

void Entity::set_movespeed(float new_movespeed)
{
    movespeed = new_movespeed;
};
float Entity::get_movespeed()
{
    return movespeed;
};
//ХП
void Entity::set_counterHP(int new_counterHP)
{
    counterHP = new_counterHP;
};
int Entity::get_counterHP()
{
    return counterHP;
};