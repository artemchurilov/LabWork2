/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <gtest/gtest.h>
#include "../src/Player/Player.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PlayerTest, PlayerConstruct)
{
    Player testPlayer(1,1);
    EXPECT_EQ(testPlayer.getX(),1);
    EXPECT_EQ(testPlayer.getY(),1);
    
    EXPECT_EQ(testPlayer.getHealth(),100);
    EXPECT_EQ(testPlayer.getEnergy(),100);
    EXPECT_EQ(testPlayer.getWood(),0);
    EXPECT_EQ(testPlayer.getStone(),0);
    EXPECT_EQ(testPlayer.getGold(),0);
}


TEST(PlayerTest, PlayerChar)
{
    Player testPlayer(1,1);
    EXPECT_EQ(testPlayer.getChar(),'P');
}

TEST(PlayerTest, Health)
{
    Player testPlayer(1,1);
    testPlayer.setHealth(42);
    testPlayer.addHealth(4);
    EXPECT_EQ(testPlayer.getHealth(),46);
}

TEST(PlayerTest, Energy)
{
    Player testPlayer(1,1);
    testPlayer.setEnergy(42);
    testPlayer.addEnergy(4);
    EXPECT_EQ(testPlayer.getEnergy(),46);
}

TEST(PlayerTest, Wood)
{
    Player testPlayer(1,1);
    testPlayer.setWood(42);
    testPlayer.addWood(4);
    EXPECT_EQ(testPlayer.getWood(),46);
}

TEST(PlayerTest, Stone)
{
    Player testPlayer(1,1);
    testPlayer.setStone(42);
    testPlayer.addStone(4);
    EXPECT_EQ(testPlayer.getStone(),46);
}

TEST(PlayerTest, Gold)
{
    Player testPlayer(1,1);
    testPlayer.setGold(42);
    testPlayer.addGold(4);
    EXPECT_EQ(testPlayer.getGold(),46);
}
