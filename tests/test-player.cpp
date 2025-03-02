/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include <gtest/gtest.h>
#include "../src/player/player.h"

TEST(PlayerTest, PlayerGetters)
{
    Player test(4, 2, 1, 10, 1, 1, 5, 100);
    EXPECT_EQ(test.get_posX(), 4);  
    EXPECT_EQ(test.get_posY(), 2);
    EXPECT_EQ(test.get_isMoveable(), 1);
    EXPECT_EQ(test.get_isCollision(), 1);
    EXPECT_EQ(test.get_movespeed(), 1);
    EXPECT_EQ(test.get_counterHP(), 10);
    EXPECT_EQ(test.get_isLiving(), 1);
    EXPECT_EQ(test.get_isSmiling(), 1);
    EXPECT_EQ(test.get_smileCost(), 5);
    EXPECT_EQ(test.get_energy(), 100);
    
}

TEST(Player, PlayerSetters) 
{
    Player test(4, 2, 1, 10, 1, 1, 5, 100);
    test.set_posX(4);  
    test.set_posY(2);      
    test.set_movespeed(42);
    test.set_counterHP(42);
    test.set_isLiving(0);
    test.set_isSmiling(0);
    test.set_smileCost(7);
    test.set_energy(95);
    EXPECT_EQ(test.get_posX(), 4);
    EXPECT_EQ(test.get_posY(), 2); 
    EXPECT_EQ(test.get_isMoveable(), 1);  
    EXPECT_EQ(test.get_isCollision(), 1);
    EXPECT_EQ(test.get_movespeed(), 42);
    EXPECT_EQ(test.get_counterHP(), 42);
    EXPECT_EQ(test.get_isLiving(), 0);
    EXPECT_EQ(test.get_isSmiling(), 0);
    EXPECT_EQ(test.get_smileCost(), 7);
    EXPECT_EQ(test.get_energy(), 95);
}

TEST(Player, PlayerSmile)
{
    Player test(4, 2, 1, 10, 1, 0, 5, 100);
    test.smile();
    EXPECT_EQ(test.get_energy(), 95);
    EXPECT_EQ(test.get_isSmiling(), 1); 
    test.smile();
    EXPECT_EQ(test.get_energy(), 90);
    test.set_smileCost(3);
    test.smile();
    EXPECT_EQ(test.get_energy(), 87);
}

TEST(Player, PlayerRest)
{
    Player test(4, 2, 1, 10, 1, 0, 5, 100);
    test.smile();
    EXPECT_EQ(test.get_energy(), 95);
    EXPECT_EQ(test.get_isSmiling(), 1); 
    test.rest();
    EXPECT_EQ(test.get_energy(), 100);
    EXPECT_EQ(test.get_isSmiling(), 0); 
}
