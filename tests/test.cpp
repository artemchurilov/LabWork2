#include "gtest/gtest.h"
#include "../src/StaticObj.h"
#include "../src/DynamicObj.h"
#include "../src/Cell.h"
#include "../src/Map.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(CellTest, DefaultIsEmpty) {
    Cell cell;
    EXPECT_EQ(cell.getSymbol(), '.');
}

TEST(CellTest, SetWallTerrain) {
    Cell cell;
    cell.setTerrain(TerrainType::WALL);
    EXPECT_EQ(cell.getSymbol(), '#');
}

TEST(CellTest, PlaceStaticObject) {
    Cell cell;
    auto tree = std::make_shared<StaticObj>('T');
    cell.setObject(tree);
    EXPECT_EQ(cell.getSymbol(), 'T');
}

TEST(CellTest, PlaceDynamicObject) {
    Cell cell;
    auto player = std::make_shared<DynamicObj>('P');
    cell.setObject(player);
    EXPECT_EQ(cell.getSymbol(), 'P');
}

TEST(CellTest, ObjectOverridesTerrain) {
    Cell cell;
    cell.setTerrain(TerrainType::WALL);
    auto obj = std::make_shared<StaticObj>('O');
    cell.setObject(obj);
    EXPECT_EQ(cell.getSymbol(), 'O');
}

TEST(CellTest, RemoveObjectRevertsToTerrain) {
    Cell cell;
    cell.setTerrain(TerrainType::WALL);
    auto obj = std::make_shared<StaticObj>('X');
    cell.setObject(obj);
    cell.setObject(nullptr);
    EXPECT_EQ(cell.getSymbol(), '#');
}


TEST(GameObjectTest, StaticObjectSymbol) {
    StaticObj tree('T');
    EXPECT_EQ(tree.getSymbol(), 'T');
}

TEST(GameObjectTest, DynamicObjectSymbol) {
    DynamicObj player('P');
    EXPECT_EQ(player.getSymbol(), 'P');
}