#include "FistPunch.h"

 
void FistPunch::play(CardPlayer& user, Enemy& target){
    target.takeDamage(12);
    user.loseEnergy(1);
}
std::string FistPunch::getName() const { return "Fist Punch"; }
int FistPunch::getEnergyCost() const { return 1; }