//
// Created by Rusewww on 20.05.2021.
//

#ifndef LAB30_MENU_H
#define LAB30_MENU_H

#include "controller.h"

class menu {
public:

    ~menu();

    static void showMainMenu();

    static void showForm();

    static void ending();

    static void showListMenu();

    static int gettingPoint();

    static void finallyWriteToFile();

    static void finallyReadFromFile();

    static void showSortMenu();

    static char getWay();

    static void Finally();

    static void addMenu();

    static void deleteMenu();

    static void showFindMenu();

    static void showDeletingMenu();
};


#endif //LAB30_MENU_H
