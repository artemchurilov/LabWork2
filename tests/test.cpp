#include "gtest/gtest.h"
#include "../src/StaticObj.h"
#include "../src/DynamicObj.h"
#include "../src/Cell.h"
#include "../src/GameMap.h"
#include "../src/Player.h"
#include <memory>


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

TEST(InventoryTest, InitialValues)
{
    Inventory inv;
    EXPECT_EQ(inv.hp, 100);
    EXPECT_EQ(inv.energy, 50);
    EXPECT_EQ(inv.gold, 0);
}

class GameMapTest : public ::testing::Test
{
protected:
    GameMap map{5, 5};
};

TEST_F(GameMapTest, InitialPlayerPosition)
{
    EXPECT_TRUE(map.movePlayer(0, 0));
}


TEST_F(GameMapTest, InvalidMoves)
{

    EXPECT_FALSE(map.movePlayer(0, -1));
    EXPECT_FALSE(map.movePlayer(-1, 0));
}


TEST(PlayerTest, SymbolAndInventory)
{
    Player p;
    EXPECT_EQ(p.getSymbol(), 'P');
    EXPECT_EQ(p.inventory.wood, 0);
}
