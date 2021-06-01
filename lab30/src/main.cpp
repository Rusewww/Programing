/**
 * @file main.cpp
 * @brief OOP. Polymorphism.
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

/**
 * function main - main program function.
 * @return 0 - successful return code
 */

#include "list.h"

int main() {
    cout << "|===========<Origin_list>===========|" << endl;
    auto *watchList = new list;
    quartzWatches watchOne(false, "One", 199, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
    watchList->addLink(&watchOne);
    quartzWatches watchTwo(true, "Two", 400, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
    watchList->addLink(&watchTwo);
    quartzWatches watchTree(false, "Tree", 24, manufacturerStruct("Rocket", "USSR"), CLASSIC, SOLAR, 95);
    watchList->addLink(&watchTree);
    mechanicalWatches watch1(false, "Four", 1400, manufacturerStruct("Timex", "USA"), CLASSIC, false, true);
    watchList->addLink(&watch1);
    mechanicalWatches watch2(true, "Five", 300, manufacturerStruct("Casio", "Japan"), SPORT, true, false);
    watchList->addLink(&watch2);
    mechanicalWatches watch3(false, "Six", 200, manufacturerStruct("Tissot", "Switzerland"), CLASSIC, true, true);
    watchList->addLink(&watch3);
    watchList->showAll();
    cout << "|-------------------------------------------|" << endl;
    cout << "|==========<Watches_Under_400USD>===========|" << endl;
    watchList->findByPrice();
    cout << "|-------------------------------------------|" << endl;
    cout << "|=============<Classic_Watches>=============|" << endl;
    watchList->findClassicWatches();
    cout << "|-------------------------------------------|" << endl;
    cout << "|====<Switzerland_Watches_With_Skeleton>====|" << endl;
    watchList->findSwitzerlandWithSkeleton();
    cout << "|-------------------------------------------|" << endl;
    quartzWatches watchFour(true, "Seven", 242, manufacturerStruct("Rocket", "USSR"), CLASSIC, SOLAR, 95);
    mechanicalWatches watch4(false, "Eight", 2200, manufacturerStruct("Tissot", "Switzerland"), CLASSIC, true, true);
    auto *watchListSecond = new list;
    watchListSecond->addLink(&watchFour);
    watchListSecond->addLink(&watch4);
    watchList->combineLists(*watchListSecond);
    watchList->sortByCost('>');
    watchList->showAll();
    cout << "|-------------------------------------------|" << endl;
    fiveTask();
    delete watchList;
    return 0;
}
