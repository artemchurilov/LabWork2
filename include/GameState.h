/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include <vector>

struct GameState
{
    struct
    {
        int hp = 100;
        int energy = 50;
        int gold = 0;
        int wood = 0;
        int stone = 0;
        int sword_level = 1;
        int shield_level = 1;
    } inventory;
    std::vector<std::string> deck_cards;
    std::vector<std::string> current_deck;
    int day = 1;
    std::string last_message;
    int campfire_x = 3;
    int campfire_y = 1;
};

#endif

