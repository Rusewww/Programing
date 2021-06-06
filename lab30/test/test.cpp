#include <gtest/gtest.h>
#include "../src/list.h"

TEST(findTests, findPriceTest){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 300, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 900, manufacturerStruct("Tissot", "Switzerland"), CLASSIC, true, true);
    watchList->addLink(&watch4);
    cout.clear(std::ios_base::badbit);
    auto test = watchList->findByPrice();
    cout.clear(std::ios_base::goodbit);
    ASSERT_TRUE(test[0]->getWaterproof());
    ASSERT_EQ(watch2.getModel(), test[0]->getModel());
    ASSERT_EQ(watch2.getCost(), test[0]->getCost());
    ASSERT_EQ(watch2.getManufacturer().getFirm(), test[0]->getManufacturer().getFirm());
    ASSERT_EQ(watch2.getManufacturer().getCountry(), test[0]->getManufacturer().getCountry());
    delete watchList;
}

TEST(findTests, findClassicTest){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 300, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 900, manufacturerStruct("Tissot", "Switzerland"), ARMOURED, true, true);
    watchList->addLink(&watch4);
    cout.clear(std::ios_base::badbit);
    auto test = watchList->findClassicWatches();
    cout.clear(std::ios_base::goodbit);
    ASSERT_FALSE(test[0]->getWaterproof());
    ASSERT_EQ(watch1.getModel(), test[0]->getModel());
    ASSERT_EQ(watch1.getCost(), test[0]->getCost());
    ASSERT_EQ(watch1.getManufacturer().getFirm(), test[0]->getManufacturer().getFirm());
    ASSERT_EQ(watch1.getManufacturer().getCountry(), test[0]->getManufacturer().getCountry());
    delete watchList;
}

TEST(findTests, findSwitzerlandWithSkeletonTest){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 300, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 900, manufacturerStruct("Tissot", "Switzerland"), ARMOURED, true, true);
    watchList->addLink(&watch4);
    cout.clear(std::ios_base::badbit);
    auto test = watchList->findSwitzerlandWithSkeleton();
    cout.clear(std::ios_base::goodbit);
    ASSERT_FALSE(test[0]->getWaterproof());
    ASSERT_EQ(watch4.getModel(), test[0]->getModel());
    ASSERT_EQ(watch4.getCost(), test[0]->getCost());
    ASSERT_EQ(watch4.getManufacturer().getFirm(), test[0]->getManufacturer().getFirm());
    ASSERT_EQ(watch4.getManufacturer().getCountry(), test[0]->getManufacturer().getCountry());
    delete watchList;
}

TEST(sortTests, testSortingByCost){
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    quartzWatches watch2(true, "Two", 300, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(true, "Five", 500, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch3);
    mechanicalWatches watch4(false, "Six", 900, manufacturerStruct("Tissot", "Switzerland"), ARMOURED, true, true);
    watchList->addLink(&watch4);

    cout.clear(std::ios_base::badbit);
    watchList->sortByCost('>');
    cout.clear(std::ios_base::goodbit);

    ASSERT_FALSE(watchList->getLink(0)->getWaterproof());
    ASSERT_EQ(watch1.getModel(), watchList->getLink(0)->getModel());
    ASSERT_EQ(watch1.getCost(), watchList->getLink(0)->getCost());
    ASSERT_EQ(watch1.getManufacturer().getFirm(), watchList->getLink(0)->getManufacturer().getFirm());
    ASSERT_EQ(watch1.getManufacturer().getCountry(), watchList->getLink(0)->getManufacturer().getCountry());

    ASSERT_FALSE(watchList->getLink(1)->getWaterproof());
    ASSERT_EQ(watch4.getModel(), watchList->getLink(1)->getModel());
    ASSERT_EQ(watch4.getCost(), watchList->getLink(1)->getCost());
    ASSERT_EQ(watch4.getManufacturer().getFirm(), watchList->getLink(1)->getManufacturer().getFirm());
    ASSERT_EQ(watch4.getManufacturer().getCountry(), watchList->getLink(1)->getManufacturer().getCountry());

    ASSERT_TRUE(watchList->getLink(2)->getWaterproof());
    ASSERT_EQ(watch3.getModel(), watchList->getLink(2)->getModel());
    ASSERT_EQ(watch3.getCost(), watchList->getLink(2)->getCost());
    ASSERT_EQ(watch3.getManufacturer().getFirm(), watchList->getLink(2)->getManufacturer().getFirm());
    ASSERT_EQ(watch3.getManufacturer().getCountry(), watchList->getLink(2)->getManufacturer().getCountry());

    ASSERT_TRUE(watchList->getLink(3)->getWaterproof());
    ASSERT_EQ(watch2.getModel(), watchList->getLink(3)->getModel());
    ASSERT_EQ(watch2.getCost(), watchList->getLink(3)->getCost());
    ASSERT_EQ(watch2.getManufacturer().getFirm(), watchList->getLink(3)->getManufacturer().getFirm());
    ASSERT_EQ(watch2.getManufacturer().getCountry(), watchList->getLink(3)->getManufacturer().getCountry());

    delete watchList;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

