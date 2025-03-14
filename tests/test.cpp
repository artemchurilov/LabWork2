#include "gtest/gtest.h"
#include "../src/StaticObj.h"
#include "../src/DynamicObj.h"
#include "../src/Cell.h"
#include "../src/GameMap.h"
#include <memory>


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

TEST(GameObjectTest, MobInteraction) {
    GameState state;
    Mob('M', 20, 10).interact(state);
    EXPECT_EQ(state.inventory.hp, 80);
    EXPECT_EQ(state.inventory.energy, 30);
    EXPECT_EQ(state.inventory.gold, 10);
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


