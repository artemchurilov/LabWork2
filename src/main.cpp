/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <iostream>
#include <memory>
#include <vector>
#include "Map.h"
#include "Cell.h"
#include "../include/const.h"

#include "StaticObj.h"
#include "DynamicObj.h"

int main() {
    Map map(MAP_WIDTH, MAP_HEIGHT);
    
    auto player = std::make_shared<DynamicObj>('P');
    auto tree = std::make_shared<StaticObj>('T');

    map.placeObject(0, 0, player);
    map.placeObject(2, 3, tree);
    map.placeObject(4, 4, tree);

    map.render();

    return 0;
}