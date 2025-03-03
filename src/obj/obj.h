/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#ifndef OBJ_H
#define OBJ_H

class Obj
{
public:
    void set_posX(int new_posX);
    int get_posX();

    void set_posY(int new_posX);
    int get_posY();

    void set_isMoveable(bool new_isMoveable);
    bool get_isMoveable();
    void set_isCollision(bool new_isCollision);
    bool get_isCollision();

    Obj(int new_posX, int new_posY, bool new_isMoveable,bool new_isCollision);
    ~Obj();
private:
    int posX, posY;    //позиция
    bool isMoveable;
    bool isCollision;
};


#endif