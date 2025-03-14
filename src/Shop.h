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

    void printSnakeArt();
    void interact(GameState& state) override;

private:

    void showShopInterface(GameState& state);
};

#endif