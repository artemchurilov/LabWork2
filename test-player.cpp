/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include <gtest/gtest.h>
#include "player.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PlayerTest, PlayerGetters)
{
    Player test(4, 2, 1);
    EXPECT_EQ(test.get_posX(), 4);  
    EXPECT_EQ(test.get_posY(), 2);   
    EXPECT_EQ(test.get_playerSpeed(), 1);
}

TEST(PlayerTest, PlayerSetters) 
{
    Player test(1, 1, 2);
    test.set_posX(4);  
    test.set_posY(2);   
    test.set_playerSpeed(1);
    EXPECT_EQ(test.get_posX(), 4);  
    EXPECT_EQ(test.get_posY(), 2);   
    EXPECT_EQ(test.get_playerSpeed(), 1);
}

TEST(PlayerTest, Movement)
{
    Player test(1, 1, 1);
    test.moveDown();
    EXPECT_EQ(test.get_posX(), 1);  
    EXPECT_EQ(test.get_posY(), 0);
    test.moveUp();
    EXPECT_EQ(test.get_posX(), 1);  
    EXPECT_EQ(test.get_posY(), 1); 
    test.set_playerSpeed(3); 
    test.moveLeft();
    EXPECT_EQ(test.get_posX(), -2);  
    EXPECT_EQ(test.get_posY(), 1); 
    test.moveRight();
    EXPECT_EQ(test.get_posX(), 1);  
    EXPECT_EQ(test.get_posY(), 1); 
}
