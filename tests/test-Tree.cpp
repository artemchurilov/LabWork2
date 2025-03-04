/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <gtest/gtest.h>
#include "../src/Tree/Tree.h"

TEST (Tree, TreeConstructor)
{
    Tree test1(4,2);
    EXPECT_EQ(test1.getX(),4);
    EXPECT_EQ(test1.getY(),2);
    EXPECT_EQ(test1.getFruitCount(),5);
}


TEST (Tree, Fruit)
{
    Tree test2(4,2);
    test2.setFruitCount(7);
    test2.addFruitCount(-5);
    EXPECT_EQ(test2.getFruitCount(),2);
}