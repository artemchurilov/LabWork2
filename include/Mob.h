/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/


#ifndef MOB_H
#define MOB_H

#include "GameObject.h"
class Mob : public GameObject
{
public:
    Mob(char s, int dmg, int reward);
    char getSymbol() const override;
    bool isPassable() const override;
    void interact(GameState& state) override;
private:
    void handleDeath(GameState& state);
    char symbol;
    int base_damage;
    int gold_reward;
};

#endif