/**
 * @file menu.h
 * @brief Файл класу меню
 *
 * @author Zoulia I.
 * @date 20-may-2021
 * @version 1.0
 */

#ifndef LAB30_MENU_H
#define LAB30_MENU_H

#include "controller.h"

/**
 * menu - класс демонстрації меню
 */

class menu {
public:

    /**
     * ~menu - деструктор класу menu
     */

    ~menu();

    /**
     * showMainMenu - виводить вікно головного меню
     */

    static void showMainMenu();

    /**
     * showForm - виводить першу графу таблиці годдиників
     */

    static void showForm();

    /**
     * ending - виводить закінччення меню
     */

    static void ending();

    /**
     * showListMenu - виводить меню списку
     */

    static void showListMenu();

    /**
     * Зчитує число, яке передає користувач
     * @return Число отримане від користувача.
     */

    static int gettingPoint();

    /**
     * finallyWriteToFile - виводить повідомлення про успішне виконання запису інформації у файл
     */

    static void finallyWriteToFile();

    /**
     * finallyReadFromFile - виводить повідомлення про успішне виконання читання інформації з файлу
     */

    static void finallyReadFromFile();

    /**
     * showSortMenu - виводить меню сортування
     */

    static void showSortMenu();

    /**
     * getWay - отримує напрямок сортування від користувача
     * @return Символ напрямку сортування.
     */

    static char getWay();

    /**
     * Finally - виводить повідомлення про успішне виконання.
     */

    static void Finally();

    /**
     * addMenu - виводить меню додавання елементу
     */

    static void addMenu();

    /**
     * deleteMenu - виводить меню видалення елементу
     */

    static void deleteMenu();

    /**
     * showFindMenu - виводить меню пошуку годинників
     */

    static void showFindMenu();

    /**
     * showDeletingMenu - виводить меню видалення списку
     */

    static void showDeletingMenu();

    /**
     * watchesUnder400 - виводить рядок з повідомленням про пошук годинників з ціною меншою за 400
     */

    static void watchesUnder400();

    /**
     * classicWatches - виводить рядок з повідомленням про пошук годинників класичного стилю
     */

    static void classicWatches();

    /**
     * switzerlandWatchesWithSkeleton - виводить рядок з повідомленням про пошук годинників зі Щвейцарії та зі скелетоном
     */

    static void switzerlandWatchesWithSkeleton();
};


#endif //LAB30_MENU_H
