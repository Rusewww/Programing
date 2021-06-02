//
// Created by Rusewww on 31.05.2021.
//
#include "menu.h"
int main(){
    auto watchList = new list;
    menu::showMainMenu();
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
    auto Control = new controller;
    Control->setList(watchList);
    menu::showForm();
    Control->showList();
    return 0;
}
