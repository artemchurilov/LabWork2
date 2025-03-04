/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/  

#include <gtest/gtest.h>
#include "../src/Player/Player.h"
#include "../src/Tree/Tree.h"

TEST(GameObject, getCollidableFalse)
{
    Player test2(1,1);
    GameObject* obj = &test2; 
    EXPECT_FALSE(obj->getCollidable());
}
TEST(GameObject, getCollidableTrue)
{
    Tree test3(1,1);
    GameObject* obj = &test3; 
    EXPECT_TRUE(obj->getCollidable());
}

TEST(GameObject, positionX)
{
    Tree test4(1,1);
    GameObject* obj = &test4;
    obj->setX(5); 
    EXPECT_EQ(obj->getX(),5);
}

TEST(GameObject, positionY)
{
    Tree test5(1,1);
    GameObject* obj = &test5;
    obj->setX(7); 
    EXPECT_EQ(obj->getX(),7);
}
