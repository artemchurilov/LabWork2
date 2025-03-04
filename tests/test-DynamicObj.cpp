/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <gtest/gtest.h>
#include "../src/Player/Player.h"

TEST(DynamicObj, Move)
{
    Player test1(1,1);
    DynamicObj* obj = &test1; 
    obj->move(4, 2);
    EXPECT_EQ(test1.getX(),5);
    EXPECT_EQ(test1.getY(),3);
}

TEST(DynamicObj, isPassable)
{
    Player test2(1,1);
    DynamicObj* obj = &test2; 
    EXPECT_TRUE(obj->isPassable());
}