/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Player.h"

Player::Player(int x, int y) : 
DynamicObj(x, y, false),health(100), energy(100), wood(0), stone(0), gold(0) 
{

}

char Player::getChar() const
{
    return 'P';
}

int Player::getHealth()
{
    return health;
};
void Player::addHealth(int _health)
{
    setHealth(getHealth()+_health);
};
void Player::setHealth(int _health)
{
    health = _health;
};



int Player::getEnergy()
{
    return energy;
};
void Player::addEnergy(int _energy)
{
    setEnergy(getEnergy()+_energy);
};
void Player::setEnergy(int _energy)
{
    energy = _energy;
};




int Player::getWood()
{
    return wood;
};
void Player::addWood(int _wood)
{
    setWood(getWood()+_wood);
};
void Player::setWood(int _wood)
{
    wood = _wood;
};





int Player::getStone()
{
    return stone;
};
void Player::addStone(int _stone)
{
    setStone(getStone()+_stone);
};
void Player::setStone(int _stone)
{
    stone = _stone;
};




int Player::getGold()
{
    return gold;
};
void Player::addGold(int _gold)
{
    setGold(getGold()+_gold);
};
void Player::setGold(int _gold)
{
    gold = _gold;
};
