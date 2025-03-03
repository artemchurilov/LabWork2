#ifndef PLAYER_H
#define PLAYER_H

#include "../entity/entity.h"

class Player : public Entity {
public:
    Player(int new_posX, int new_posY, int new_movespeed, 
           int new_counterHP, bool new_isLiving, bool new_isSmiling,
           int new_smileCost, int new_energy);
    ~Player();

    void smile();
    void rest();

    void set_isLiving(bool new_isLiving);
    bool get_isLiving() const;
    
    void set_isSmiling(bool new_isSmiling);
    bool get_isSmiling() const;
    
    void set_energy(int new_energy);
    int get_energy() const;
    
    void set_smileCost(int new_smileCost);
    int get_smileCost() const;

private:
    bool isLiving;
    bool isSmiling;
    int smileCost;
    int energy;
    
};
#endif