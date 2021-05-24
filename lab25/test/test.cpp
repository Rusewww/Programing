#include "../src/list.h"
#include <gtest/gtest.h>

TEST(OperatorsTest, assignmentOperator){
    watch watchOne(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
    watch watchTwo;
    watchTwo = watchOne;
    ASSERT_TRUE(watchTwo.getWaterproof());
    ASSERT_EQ(watchOne.getModel(),watchTwo.getModel());
    ASSERT_EQ(watchOne.getCost(),watchTwo.getCost());
    ASSERT_EQ(watchOne.getManufacturer().getFirm(),watchTwo.getManufacturer().getFirm());
    ASSERT_EQ(watchOne.getManufacturer().getCountry(),watchTwo.getManufacturer().getCountry());
    ASSERT_EQ(watchOne.getStyle(),watchTwo.getStyle());
}

TEST(OperatorsTest, comparisonOperator){
    watch watchOne(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
    watch watchTwo(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
    ASSERT_TRUE(watchOne == watchTwo);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}