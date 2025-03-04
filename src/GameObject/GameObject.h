/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject 
{
    public:
        GameObject(int x, int y, bool collidable);
        virtual ~GameObject() = default;        
        virtual char getChar() const = 0;
        virtual bool isPassable() const;
        //virtual void onPlayerEnter(Player& player) = 0;

        int getX();
        void setX(int _x);
        int getY();
        void setY(int _y);
        bool getCollidable();
    protected:
        int x, y;
        bool isCollidable;

};

#endif