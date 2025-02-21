/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#include <gtest/gtest.h>
#include "obj.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(ObjTest, ObjGetters)
{
    Obj test(4, 2, 0, 0);
    EXPECT_EQ(test.get_posX(), 4);  
    EXPECT_EQ(test.get_posY(), 2);
    EXPECT_EQ(test.get_isMoveable(), 0);
    EXPECT_EQ(test.get_isCollision(), 0);     
}

TEST(ObjTest, ObjSetters) 
{
    Obj test(1, 1, 0, 0);
    test.set_posX(4);  
    test.set_posY(2);
    test.set_isMoveable(1);  
    test.set_isCollision(1);      
    EXPECT_EQ(test.get_posX(), 4);
    EXPECT_EQ(test.get_posY(), 2); 
    EXPECT_EQ(test.get_isMoveable(), 1);  
    EXPECT_EQ(test.get_isCollision(), 1);
}