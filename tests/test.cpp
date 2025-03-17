#include "gtest/gtest.h"
#include "../include/Cell.h"
#include "../include/GameMap.h"
#include "../include/Shop.h"

#include "../include/Tree.h"
#include "../include/Stone.h"
#include "../include/Mob.h"
#include "../include/Campfire.h"
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CellTest, WaterTerrainBlocksMovement)
{
    Cell cell;
    cell.setTerrain(TerrainType::WATER);
    EXPECT_FALSE(cell.isPassable());
    EXPECT_EQ(cell.getSymbol(), '~');
}


class GameMapTest : public ::testing::Test
{
protected:
    GameMap map{5, 5};
};

TEST(GameStateTest, InitialValues) {
    GameState state;
    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 1);
}

TEST(GameObjectTest, TreeInteraction) {
    GameState state;
    Tree().interact(state);
    EXPECT_EQ(state.inventory.energy, 40);
    EXPECT_EQ(state.inventory.wood, 1);
}

TEST(GameObjectTest, StoneInteraction) {
    GameState state;
    Stone().interact(state);
    EXPECT_EQ(state.inventory.energy, 35);
    EXPECT_EQ(state.inventory.stone, 1);
}

TEST(GameObjectTest, CampfireInteraction) {
    GameState state;
    state.inventory.hp = 50;
    state.inventory.energy = 20;
    Campfire().interact(state);
    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 2);
}



TEST(CellTest, ObjectInteraction) {
    Cell cell;
    cell.setObject(std::make_shared<Tree>());
    GameState state;
    cell.interact(state);
    EXPECT_EQ(state.inventory.wood, 1);
}

TEST(CellTest, PassabilityCheck) {
    Cell cell;
    cell.setObject(std::make_shared<Tree>());
    EXPECT_FALSE(cell.isPassable());
}


TEST(GameStateTest, DeathResetsResources) {
    GameState state;
    state.inventory = {0, 0, 100, 5, 3, 2, 3}; // HP=0
    Mob('D', 100, 0).interact(state); // Вызовет handleDeath
    
    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.gold, 0);
    EXPECT_EQ(state.inventory.wood, 0);
    EXPECT_EQ(state.inventory.stone, 0);
    EXPECT_EQ(state.inventory.sword_level, 2); // Сохраняются уровни
    EXPECT_EQ(state.inventory.shield_level, 3);
    EXPECT_EQ(state.day, 2);
}

TEST(MobTest, DamageCalculation) {
    GameState state;
    state.inventory.shield_level = 3;
    Mob('M', 25, 10).interact(state);
    
    // 25 - (3*5) = 10 damage
    EXPECT_EQ(state.inventory.hp, 90);
    EXPECT_EQ(state.inventory.gold, 10);
    EXPECT_EQ(state.last_message, "Fought M! Lost 10 HP. Got 10 gold.");
}


#include "../include/CardPlayer.h"
TEST(CardPlayerTest, Initialization) {
    CardPlayer player;
    EXPECT_EQ(player.getHealth(), 50);
    EXPECT_EQ(player.getEnergy(), 3);
    EXPECT_EQ(player.getHand().size(), 5);
}

TEST(CardPlayerTest, DamageCalculation) {
    CardPlayer player;
    
    player.addBlock(5);
    player.takeDamage(3);
    EXPECT_EQ(player.getBlock(), 2);
    EXPECT_EQ(player.getHealth(), 50);
    player.takeDamage(10);
    EXPECT_EQ(player.getBlock(), 0);
    EXPECT_EQ(player.getHealth(), 42);
}



TEST(EnemyAITest, CardPrioritization) {
    Enemy enemy;
    CardPlayer player;
    
    
    player.takeDamage(30); 
    enemy.executeTurn(player);
    
    EXPECT_LT(player.getHealth(), 20);
}


