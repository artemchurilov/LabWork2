#include "player.h"
#include <algorithm>
#include <iostream>

// Конструктор и деструктор
Player::Player(int new_posX, int new_posY, int new_movespeed, 
              int new_counterHP, bool new_isLiving, bool new_isSmiling,
              int new_smileCost, int new_energy)
    : Entity(new_posX, new_posY, new_movespeed, new_counterHP),
      isLiving(new_isLiving),
      isSmiling(new_isSmiling),
      smileCost(new_smileCost),
      energy(new_energy) {}

Player::~Player() {
}

// Логика движения

// Остальные методы
void Player::smile() {
    if(get_energy() >= get_smileCost()) {
        set_energy(get_energy() - get_smileCost());
        set_isSmiling(true);
    }
}

void Player::rest() {
    set_energy(100);
    set_isSmiling(false);
}

// Геттеры и сеттеры
void Player::set_isLiving(bool new_isLiving) { isLiving = new_isLiving; }
bool Player::get_isLiving() const { return isLiving; }

void Player::set_isSmiling(bool new_isSmiling) { isSmiling = new_isSmiling; }
bool Player::get_isSmiling() const { return isSmiling; }

void Player::set_energy(int new_energy) { energy = new_energy; }
int Player::get_energy() const { return energy; }

void Player::set_smileCost(int new_smileCost) { smileCost = new_smileCost; }
int Player::get_smileCost() const { return smileCost; }
