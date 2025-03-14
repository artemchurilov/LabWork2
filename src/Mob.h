/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "GameObject.h"
#include "GameState.h"
class Mob : public GameObject
{
public:
    Mob(char s, int dmg, int reward);
    char getSymbol() const override;
    bool isPassable() const override;
    void interact(GameState& state) const override;
private:
    char symbol;
    int damage;
    int gold_reward;
};