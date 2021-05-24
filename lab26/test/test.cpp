#include "../src/list.h"
#include <gtest/gtest.h>

TEST(successorTest, quartzSuccessorFindPrice) {
    auto *quartzWatch = new quartzWatchesList;
    quartzWatches watchOne(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    quartzWatch->addLink(watchOne);
    quartzWatches watchTwo(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    quartzWatch->addLink(watchTwo);
    quartzWatches watchTree(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, SOLAR, 95);
    quartzWatch->addLink(watchTree);
    cout.clear(std::ios_base::badbit);
    quartzWatches test = quartzWatch->findByPrice(1500);
    cout.clear(std::ios_base::goodbit);
    ASSERT_TRUE(test.getWaterproof());
    ASSERT_EQ(watchTwo.getModel(), test.getModel());
    ASSERT_EQ(watchTwo.getCost(), test.getCost());
    ASSERT_EQ(watchTwo.getManufacturer().getFirm(), test.getManufacturer().getFirm());
    ASSERT_EQ(watchTwo.getManufacturer().getCountry(), test.getManufacturer().getCountry());
    ASSERT_EQ(watchTwo.getStyle(), test.getStyle());
    delete quartzWatch;
}

TEST(successorTest, quartzSuccessorFindClassic) {
    auto *quartzWatch = new quartzWatchesList;
    quartzWatches watchOne(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), ARMOURED, GRAPHENE, 400);
    quartzWatch->addLink(watchOne);
    quartzWatches watchTwo(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    quartzWatch->addLink(watchTwo);
    quartzWatches watchTree(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, SOLAR, 95);
    quartzWatch->addLink(watchTree);
    cout.clear(std::ios_base::badbit);
    quartzWatches test = quartzWatch->findClassicWatches();
    cout.clear(std::ios_base::goodbit);
    ASSERT_FALSE(test.getWaterproof());
    ASSERT_EQ(watchTree.getModel(), test.getModel());
    ASSERT_EQ(watchTree.getCost(), test.getCost());
    ASSERT_EQ(watchTree.getManufacturer().getFirm(), test.getManufacturer().getFirm());
    ASSERT_EQ(watchTree.getManufacturer().getCountry(), test.getManufacturer().getCountry());
    ASSERT_EQ(watchTree.getStyle(), test.getStyle());
    delete quartzWatch;
}

TEST(successorTest, mechanicalSuccessorFindPrice) {
    auto *mechanicalWatch = new mechanicalWatchList;
    mechanicalWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Switzerland"), CLASSIC, false, true);
    mechanicalWatch->addLink(watch1);
    mechanicalWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, true, false);
    mechanicalWatch->addLink(watch2);
    mechanicalWatches watch3(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, true, false);
    mechanicalWatch->addLink(watch3);
    cout.clear(std::ios_base::badbit);
    mechanicalWatches test = mechanicalWatch->findByPrice(1500);
    cout.clear(std::ios_base::goodbit);
    ASSERT_TRUE(test.getWaterproof());
    ASSERT_EQ(watch2.getModel(), test.getModel());
    ASSERT_EQ(watch2.getCost(), test.getCost());
    ASSERT_EQ(watch2.getManufacturer().getFirm(), test.getManufacturer().getFirm());
    ASSERT_EQ(watch2.getManufacturer().getCountry(), test.getManufacturer().getCountry());
    ASSERT_EQ(watch2.getStyle(), test.getStyle());
    delete mechanicalWatch;
}

TEST(successorTest, mechanicalSuccessorFindClassic) {
    auto *mechanicalWatch = new mechanicalWatchList;
    mechanicalWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Switzerland"), ARMOURED, false, true);
    mechanicalWatch->addLink(watch1);
    mechanicalWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, true, false);
    mechanicalWatch->addLink(watch2);
    mechanicalWatches watch3(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, true, false);
    mechanicalWatch->addLink(watch3);
    cout.clear(std::ios_base::badbit);
    mechanicalWatches test = mechanicalWatch->findClassicWatches();
    cout.clear(std::ios_base::goodbit);
    ASSERT_FALSE(test.getWaterproof());
    ASSERT_EQ(watch3.getModel(), test.getModel());
    ASSERT_EQ(watch3.getCost(), test.getCost());
    ASSERT_EQ(watch3.getManufacturer().getFirm(), test.getManufacturer().getFirm());
    ASSERT_EQ(watch3.getManufacturer().getCountry(), test.getManufacturer().getCountry());
    ASSERT_EQ(watch3.getStyle(), test.getStyle());
    delete mechanicalWatch;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}