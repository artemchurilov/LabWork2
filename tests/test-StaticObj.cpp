/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <gtest/gtest.h>
#include "../src/Tree/Tree.h"

TEST(StaticObj, isPassable)
{
    Tree test1(1,1);
    StaticObj* obj = &test1; 
    EXPECT_FALSE(obj->isPassable());
}