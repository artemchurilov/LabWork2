/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef SHOP_H
#define SHOP_H

#include "GameObject.h"

/**
 * @class Shop
 * @brief Represents a shop where players can upgrade their sword and shield.
 * @details Inherits from GameObject and blocks movement. Interaction triggers a menu-driven UI.
 */
class Shop : public GameObject
{
public:
    void interact(GameState& state) override;
    bool isPassable() const override { return false; }
    char getSymbol() const override { return 'S'; }
private:
    void renderShopInterface(const GameState& state);
    void handleShopInput(GameState& state);
    int selectedItem = 0;
    bool inShop = false;
};

#endif
