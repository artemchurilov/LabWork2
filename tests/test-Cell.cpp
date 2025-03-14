#include "gtest/gtest.h"
#include "../src/Cell.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CellTest, DefaultIsEmpty) {
    Cell cell;
    EXPECT_EQ(cell.getSymbol(), ' ');
}

TEST(CellTest, SetTypeChangesSymbol) {
    Cell cell;
    cell.setType(CellType::WALL);
    EXPECT_EQ(cell.getSymbol(), '#');
    
    cell.setType(CellType::PLAYER);
    EXPECT_EQ(cell.getSymbol(), 'P');
}
