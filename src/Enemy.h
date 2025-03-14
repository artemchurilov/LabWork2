/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <memory>
#include "EnemyCard.h"
#include "CardPlayer.h"

class Enemy {
    int health = 100;
    std::vector<std::unique_ptr<EnemyCard>> cards;
    
public:
    Enemy();
    
    void takeDamage(int amount) { health -= amount; }
    bool isAlive() const { return health > 0; }
    void executeTurn(CardPlayer& target);
    void printStatus() const;
};

#endif