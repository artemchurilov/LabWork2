/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include "player.h"

//конструкторыяИдеструкторы
Player::Player(int new_posX, int new_posY, int new_playerSpeed):posX(new_posX),posY(new_posY),playerSpeed(new_playerSpeed)
{

};
Player::~Player()
{

};
//позиция

void Player::set_posX(int new_posX)
{
    posX = new_posX;
};
int Player::get_posX()
{
    return posX;
};

void Player::set_posY(int new_posY)
{
    posY = new_posY;
};
int Player::get_posY()
{
    return posY;
};

void Player::moveUp()
{
    set_posY(get_posY()+playerSpeed);
};
void Player::moveRight()
{
    set_posX(get_posX()+playerSpeed);
};
void Player::moveDown()
{
    set_posY(get_posY()-playerSpeed);
};
void Player::moveLeft()
{
    set_posX(get_posY()-playerSpeed);
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