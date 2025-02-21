/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    void set_posX(int new_posX);
    int get_posX();

    void set_posY(int new_posX);
    int get_posY();
    
    void set_playerSpeed(int new_playerSpeed);
    int get_playerSpeed();
    
    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();

    Player(int new_posX, int new_posY, int new_playerSpeed);
    ~Player();
private:
    int posX, posY;    //позиция
    int playerSpeed;
};


#endif