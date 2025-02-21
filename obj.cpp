/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include "obj.h"

//конструкторыяИдеструкторы
Obj::Obj(int new_posX, int new_posY,bool new_isMoveable, bool new_isCollision):posX(new_posX),posY(new_posY),isMoveable(new_isMoveable), isCollision(new_isCollision)
{

};
Obj::~Obj()
{

};
//позиция

void Obj::set_posX(int new_posX)
{
    posX = new_posX;
};
int Obj::get_posX()
{
    return posX;
};

void Obj::set_posY(int new_posY)
{
    posY = new_posY;
};
int Obj::get_posY()
{
    return posY;
};

void Obj::set_isMoveable(bool new_isMoveable)
{
    isMoveable = new_isMoveable;
};
bool Obj::get_isMoveable()
{
    return isMoveable;
};
void Obj::set_isCollision(bool new_isCollision)
{
    isCollision = new_isCollision;
};
bool Obj::get_isCollision()
{
    return isCollision;
};



/*
void Obj::moveUp()
{
    set_posY(get_posY()+1);
};
void Obj::moveRight()
{
    set_posX(get_posX()+1);
};
void Obj::moveDown()
{
    set_posY(get_posY()-1);
};
void Obj::moveLeft()
{
    set_posX(get_posY()-1);
};

//скорость
int Player::get_playerSpeed()
{
    return playerSpeed;
};
void Player::set_playerSpeed(int new_playerSpeed)
{
    playerSpeed = new_playerSpeed;
};
*/