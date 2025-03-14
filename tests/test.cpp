#include "gtest/gtest.h"
#include "../src/StaticObj.h"
#include "../src/DynamicObj.h"
#include "../src/Cell.h"
#include "../src/GameMap.h"
#include "../src/Shop.h"


#include "gtest/gtest.h"
#include "../src/Tree.h"
#include "../src/Stone.h"
#include "../src/Mob.h"
#include "../src/Campfire.h"
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

TEST(CellTest, PassableStaticObject)
{
    auto obj = std::make_shared<StaticObj>('@', true);
    Cell cell;
    cell.setObject(obj);
    EXPECT_TRUE(cell.isPassable());
}

TEST(CellTest, NonPassableStaticObject)
{
    auto obj = std::make_shared<StaticObj>('#', false);
    Cell cell;
    cell.setObject(obj);
    EXPECT_FALSE(cell.isPassable());
}

TEST(GameObjectTest, StaticObjectPassability)
{
    StaticObj passable('+', true);
    StaticObj nonPassable('X', false);
    EXPECT_TRUE(passable.isPassable());
    EXPECT_FALSE(nonPassable.isPassable());
}

TEST(GameObjectTest, DynamicObjectIsAlwaysPassable)
{
    DynamicObj obj('D');
    EXPECT_TRUE(obj.isPassable());
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

TEST(ShopTest, SuccessfulUpgrade) {
    GameState state;
    state.inventory.gold = 100;
    Shop shop;
    
    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    
    shop.interact(state);
    
    EXPECT_EQ(state.inventory.sword_level, 2);
    EXPECT_EQ(state.inventory.gold, 50);
    EXPECT_EQ(state.last_message, "Sword upgraded to level 2");
}

TEST(ShopTest, NotEnoughGold) {
    GameState state;
    state.inventory.gold = 30;
    Shop shop;
    
    std::istringstream input("2");
    std::cin.rdbuf(input.rdbuf());
    
    shop.interact(state);
    
    EXPECT_EQ(state.inventory.shield_level, 1);
    EXPECT_EQ(state.last_message, "Not enough gold!");
}

#include "../src/CardPlayer.h"
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

#include "../src/Strike.h"
TEST(CardTest, StrikeUsage) {
    CardPlayer player;
    Enemy enemy;
    Strike strike;
    
    strike.play(player, enemy);
    EXPECT_EQ(enemy.isAlive(), true);
    EXPECT_EQ(player.getEnergy(), 2);
}

#include "../src/Defend.h"
TEST(CardTest, DefendWithWeak) {
    CardPlayer player;
    Enemy enemy;
    Defend defend;
    
    player.addWeak(1);
    defend.play(player, enemy);
    EXPECT_EQ(player.getBlock(), 3);
}


TEST(EnemyAITest, CardPrioritization) {
    Enemy enemy;
    CardPlayer player;
    
    
    player.takeDamage(30); 
    enemy.executeTurn(player);
    
    EXPECT_LT(player.getHealth(), 20);
}

