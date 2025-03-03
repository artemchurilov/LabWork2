/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 2 "Creating Game Engine"
*/

#include "battlefield.h"
#include <iostream>

Battlefield::Battlefield(int w, int h) : width(w), height(h) {
    grid = new Obj**[height];
    for (int i = 0; i < height; ++i) {
        grid[i] = new Obj*[width]();
    }
}

Battlefield::~Battlefield() {
    for (int i = 0; i < height; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

bool Battlefield::addObject(int x, int y, Obj* obj) {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    if (grid[y][x] != nullptr) return false;
    
    grid[y][x] = obj;
    obj->set_posX(x);
    obj->set_posY(y);
    return true;
}


void Battlefield::removeObject(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    grid[y][x] = nullptr;
}

Obj* Battlefield::getObject(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return nullptr;
    return grid[y][x];
}

void Battlefield::printBattlefield() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << (grid[i][j] ? "■ " : "□ ");
        }
        std::cout << std::endl;
    }
}
