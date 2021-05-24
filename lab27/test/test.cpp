#include "../src/list.h"
#include <gtest/gtest.h>

TEST(successorTest, mechanicalSuccessorFindPrice){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 3500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 9000, manufacturerStruct("Tissot", "Switzerland"), CLASSIC, true, true);
    watchList->addLink(&watch4);
    cout.clear(std::ios_base::badbit);
    auto test = watchList->findByPrice(1500);
    cout.clear(std::ios_base::goodbit);
    ASSERT_TRUE(test->getWaterproof());
    ASSERT_EQ(watch2.getModel(), test->getModel());
    ASSERT_EQ(watch2.getCost(), test->getCost());
    ASSERT_EQ(watch2.getManufacturer().getFirm(), test->getManufacturer().getFirm());
    ASSERT_EQ(watch2.getManufacturer().getCountry(), test->getManufacturer().getCountry());
    delete watchList;
}

TEST(successorTest, mechanicalSuccessorFindClassic){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), ARMOURED, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 3500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 9000, manufacturerStruct("Tissot", "Switzerland"), CLASSIC, true, true);
    watchList->addLink(&watch4);
    cout.clear(std::ios_base::badbit);
    auto test = watchList->findClassicWatches();
    cout.clear(std::ios_base::goodbit);
    ASSERT_FALSE(test->getWaterproof());
    ASSERT_EQ(watch4.getModel(), test->getModel());
    ASSERT_EQ(watch4.getCost(), test->getCost());
    ASSERT_EQ(watch4.getManufacturer().getFirm(), test->getManufacturer().getFirm());
    ASSERT_EQ(watch4.getManufacturer().getCountry(), test->getManufacturer().getCountry());
    ASSERT_EQ(watch4.getStyle(), test->getStyle());
    delete watchList;
}

TEST(successorTest, mechanicalSuccessorFindSwitzerlandWithSkeleton){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), ARMOURED, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 3500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 9000, manufacturerStruct("Tissot", "Switzerland"), CLASSIC, true, true);
    watchList->addLink(&watch4);
    cout.clear(std::ios_base::badbit);
    auto test = watchList->findSwitzerlandWithSkeleton();
    cout.clear(std::ios_base::goodbit);
    ASSERT_FALSE(test->getWaterproof());
    ASSERT_EQ(watch4.getModel(), test->getModel());
    ASSERT_EQ(watch4.getCost(), test->getCost());
    ASSERT_EQ(watch4.getManufacturer().getFirm(), test->getManufacturer().getFirm());
    ASSERT_EQ(watch4.getManufacturer().getCountry(), test->getManufacturer().getCountry());
    ASSERT_EQ(watch4.getStyle(), test->getStyle());

    delete watchList;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}