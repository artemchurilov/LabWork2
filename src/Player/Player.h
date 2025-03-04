/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "../DynamicObj/DynamicObj.h"

class Player : public DynamicObj {
public:
    Player(int x, int y);
    char getChar() const override;

    int getHealth();
    void addHealth(int _health);
    void setHealth(int _health);

    int getEnergy();
    void addEnergy(int _energy);
    void setEnergy(int _energy);


    int getWood();
    void addWood(int _wood);
    void setWood(int _wood);

    int getStone();
    void addStone(int _stone);
    void setStone(int _stone);

    int getGold();
    void addGold(int _gold);
    void setGold(int _gold);

private:
    int health;
    int energy;
    int wood, stone, gold;

};

#endif