/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <gtest/gtest.h>
#include "../src/Stone/Stone.h"

TEST (Stone, StoneConstructor)
{
    Stone test1(4,2);
    EXPECT_EQ(test1.getX(),4);
    EXPECT_EQ(test1.getY(),2);
    EXPECT_EQ(test1.getStoneCount(),5);
}


TEST (Stone, StoneNum)
{
    Stone test2(4,2);
    test2.setStoneCount(7);
    test2.addStoneCount(-5);
    EXPECT_EQ(test2.getStoneCount(),2);
}