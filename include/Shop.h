/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef SHOP_H
#define SHOP_H


#include "GameObject.h"

class Shop : public GameObject
{
public:
    char getSymbol() const override;
    bool isPassable() const override;
    void printShieldArt(int level) const;
    void printSwordArt(int level) const;
    void upgradeSword(GameState& state);
    void upgradeShield(GameState& state);
    void showSuccess(const std::string& title, const std::string& message) const;
    void showError(const std::string& message) const;
    void interact(GameState& state) override;
    void printShopArt(const GameState& state) const;

    int getShopChoice() const;
};

#endif