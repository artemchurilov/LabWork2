/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <memory>
#include "EnemyCard.h"
#include "CardPlayer.h"

class Enemy
{
    int health = 100;
    std::vector<std::unique_ptr<EnemyCard>> cards;

public:
    Enemy();
    int getHealth();
    void takeDamage(int amount);
    bool isAlive() const;
    void executeTurn(CardPlayer& target);
    void setHealth(int health);
    void printStatus() const;
};

#endif