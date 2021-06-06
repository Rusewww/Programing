#include <gtest/gtest.h>
#include "../src/controller.h"

TEST(controllerTest, sortingTest) {
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 199, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    mechanicalWatches watch2(false, "Four", 1400, manufacturerStruct("Timex", "USA"), CLASSIC, false, true);
    watchList->addLink(&watch2);
    quartzWatches watch3(true, "Two", 400, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch3);
    controller Control;
    Control.setList(watchList);

    Control.sorting('>', 2);

    ASSERT_FALSE(Control.watchList.getLink(0)->getWaterproof());
    ASSERT_EQ(watch2.getModel(), Control.watchList.getLink(0)->getModel());
    ASSERT_EQ(watch2.getCost(), Control.watchList.getLink(0)->getCost());
    ASSERT_EQ(watch2.getManufacturer().getFirm(), Control.watchList.getLink(0)->getManufacturer().getFirm());
    ASSERT_EQ(watch2.getManufacturer().getCountry(), Control.watchList.getLink(0)->getManufacturer().getCountry());
    ASSERT_EQ(watch2.getStyle(), Control.watchList.getLink(0)->getStyle());

    ASSERT_TRUE(Control.watchList.getLink(1)->getWaterproof());
    ASSERT_EQ(watch3.getModel(), Control.watchList.getLink(1)->getModel());
    ASSERT_EQ(watch3.getCost(), Control.watchList.getLink(1)->getCost());
    ASSERT_EQ(watch3.getManufacturer().getFirm(), Control.watchList.getLink(1)->getManufacturer().getFirm());
    ASSERT_EQ(watch3.getManufacturer().getCountry(), Control.watchList.getLink(1)->getManufacturer().getCountry());
    ASSERT_EQ(watch3.getStyle(), Control.watchList.getLink(1)->getStyle());

    ASSERT_FALSE(Control.watchList.getLink(2)->getWaterproof());
    ASSERT_EQ(watch1.getModel(), Control.watchList.getLink(2)->getModel());
    ASSERT_EQ(watch1.getCost(), Control.watchList.getLink(2)->getCost());
    ASSERT_EQ(watch1.getManufacturer().getFirm(), Control.watchList.getLink(2)->getManufacturer().getFirm());
    ASSERT_EQ(watch1.getManufacturer().getCountry(), Control.watchList.getLink(2)->getManufacturer().getCountry());
    ASSERT_EQ(watch1.getStyle(), Control.watchList.getLink(2)->getStyle());

    Control.sorting('<', 2);

    ASSERT_FALSE(Control.watchList.getLink(2)->getWaterproof());
    ASSERT_EQ(watch2.getModel(), Control.watchList.getLink(2)->getModel());
    ASSERT_EQ(watch2.getCost(), Control.watchList.getLink(2)->getCost());
    ASSERT_EQ(watch2.getManufacturer().getFirm(), Control.watchList.getLink(2)->getManufacturer().getFirm());
    ASSERT_EQ(watch2.getManufacturer().getCountry(), Control.watchList.getLink(2)->getManufacturer().getCountry());
    ASSERT_EQ(watch2.getStyle(), Control.watchList.getLink(2)->getStyle());

    ASSERT_TRUE(Control.watchList.getLink(1)->getWaterproof());
    ASSERT_EQ(watch3.getModel(), Control.watchList.getLink(1)->getModel());
    ASSERT_EQ(watch3.getCost(), Control.watchList.getLink(1)->getCost());
    ASSERT_EQ(watch3.getManufacturer().getFirm(), Control.watchList.getLink(1)->getManufacturer().getFirm());
    ASSERT_EQ(watch3.getManufacturer().getCountry(), Control.watchList.getLink(1)->getManufacturer().getCountry());
    ASSERT_EQ(watch3.getStyle(), Control.watchList.getLink(1)->getStyle());

    ASSERT_FALSE(Control.watchList.getLink(0)->getWaterproof());
    ASSERT_EQ(watch1.getModel(), Control.watchList.getLink(0)->getModel());
    ASSERT_EQ(watch1.getCost(), Control.watchList.getLink(0)->getCost());
    ASSERT_EQ(watch1.getManufacturer().getFirm(), Control.watchList.getLink(0)->getManufacturer().getFirm());
    ASSERT_EQ(watch1.getManufacturer().getCountry(), Control.watchList.getLink(0)->getManufacturer().getCountry());
    ASSERT_EQ(watch1.getStyle(), Control.watchList.getLink(0)->getStyle());

    delete watchList;
}

TEST(controllerTest, findTest) {
    auto *watchList = new list;
    quartzWatches watch1(false, "One", 199, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watch1);
    mechanicalWatches watch2(false, "Four", 1400, manufacturerStruct("Timex", "Switzerland"), ARMOURED, false, true);
    watchList->addLink(&watch2);
    quartzWatches watch3(true, "Two", 500, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watch3);
    controller Control;
    Control.setList(watchList);

    cout.clear(std::ios_base::badbit);
    auto watchTest = Control.find(1);
    cout.clear(std::ios_base::goodbit);

    ASSERT_FALSE(watchTest[0]->getWaterproof());
    ASSERT_EQ(watchTest[0]->getModel(), watch1.getModel());
    ASSERT_EQ(watchTest[0]->getCost(), watch1.getCost());
    ASSERT_EQ(watchTest[0]->getManufacturer().getFirm(), watch1.getManufacturer().getFirm());
    ASSERT_EQ(watchTest[0]->getManufacturer().getCountry(), watch1.getManufacturer().getCountry());
    ASSERT_EQ(watchTest[0]->getStyle(), watch1.getStyle());

    cout.clear(std::ios_base::badbit);
    auto watchTestSecond = Control.find(2);
    cout.clear(std::ios_base::goodbit);

    ASSERT_FALSE(watchTestSecond[0]->getWaterproof());
    ASSERT_EQ(watchTestSecond[0]->getModel(), watch1.getModel());
    ASSERT_EQ(watchTestSecond[0]->getCost(), watch1.getCost());
    ASSERT_EQ(watchTestSecond[0]->getManufacturer().getFirm(), watch1.getManufacturer().getFirm());
    ASSERT_EQ(watchTestSecond[0]->getManufacturer().getCountry(), watch1.getManufacturer().getCountry());
    ASSERT_EQ(watchTestSecond[0]->getStyle(), watch1.getStyle());

    cout.clear(std::ios_base::badbit);
    auto watchTestThird = Control.find(3);
    cout.clear(std::ios_base::goodbit);

    ASSERT_FALSE(watchTestThird[0]->getWaterproof());
    ASSERT_EQ(watchTestThird[0]->getModel(), watch2.getModel());
    ASSERT_EQ(watchTestThird[0]->getCost(), watch2.getCost());
    ASSERT_EQ(watchTestThird[0]->getManufacturer().getFirm(), watch2.getManufacturer().getFirm());
    ASSERT_EQ(watchTestThird[0]->getManufacturer().getCountry(), watch2.getManufacturer().getCountry());
    ASSERT_EQ(watchTestThird[0]->getStyle(), watch2.getStyle());
    delete watchList;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}