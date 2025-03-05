/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "vector"
#include "../Player/Player.h"
#include "../Tree/Tree.h"
#include "../Stone/Stone.h"

class GameMap {
    private:
        const int width = 6;
        const int height = 6;
        Player* player;
        std::vector<std::vector<GameObject*>> grid;
    
    public:
        GameMap();
        void draw() const;
        bool movePlayer(int dx, int dy);
    };