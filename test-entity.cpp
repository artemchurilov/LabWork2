/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include <gtest/gtest.h>
#include "entity.h"

TEST(EntityTest, EntityGetters)
{
    Entity test(4, 2, 1, 10);
    EXPECT_EQ(test.get_posX(), 4);  
    EXPECT_EQ(test.get_posY(), 2);
    EXPECT_EQ(test.get_isMoveable(), 1);
    EXPECT_EQ(test.get_isCollision(), 1);
    EXPECT_EQ(test.get_movespeed(), 1);
    EXPECT_EQ(test.get_counterHP(), 10);
}

TEST(Entity, EntitySetters) 
{
    Entity test(1, 1, 1, 10);
    test.set_posX(4);  
    test.set_posY(2);      
    test.set_movespeed(42);
    test.set_counterHP(42);
    EXPECT_EQ(test.get_posX(), 4);
    EXPECT_EQ(test.get_posY(), 2); 
    EXPECT_EQ(test.get_isMoveable(), 1);  
    EXPECT_EQ(test.get_isCollision(), 1);
    EXPECT_EQ(test.get_movespeed(), 42);
    EXPECT_EQ(test.get_counterHP(), 42);
}

TEST(Entity, EntityMovement)
{
    Entity test(1, 1, 1, 10);
    test.moveDown();
    EXPECT_EQ(test.get_posX(), 1);  
    EXPECT_EQ(test.get_posY(), 0);
    test.moveUp();
    EXPECT_EQ(test.get_posX(), 1);  
    EXPECT_EQ(test.get_posY(), 1); 
    test.set_movespeed(3); 
    test.moveLeft();
    EXPECT_EQ(test.get_posX(), -2);  
    EXPECT_EQ(test.get_posY(), 1); 
    test.moveRight();
    EXPECT_EQ(test.get_posX(), 1);  
    EXPECT_EQ(test.get_posY(), 1); 
}
