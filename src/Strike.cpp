
#include "Strike.h"
#include "CardPlayer.h"
#include "Enemy.h"

void Strike::play(CardPlayer& user, Enemy& target) {
    target.takeDamage(6);
    user.loseEnergy(1);
}