/**
 * @file menu.cpp
 * @brief Код функцій задекларованих у menu.h
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */


#include "menu.h"

void menu::showMainMenu() {
    cout
            << ("|=====================================================<Main_menu>=====================================================|")
            << endl;
    cout << ("| 1 - Show list") << endl;
    cout << ("| 2 - Write list to file") << endl;
    cout << ("| 3 - Read list from file") << endl;
    cout << ("| 4 - Sort") << endl;
    cout << ("| 5 - Add link") << endl;
    cout << ("| 6 - Delete link") << endl;
    cout << ("| 7 - Find watches") << endl;
    cout << ("| 8 - Delete all list") << endl;
    cout << ("| 9 - Exit") << endl;
    menu::ending();
}

void menu::showForm() {
    cout << "|";
    cout.width(11);
    cout << "Waterproof|";
    cout.width(10);
    cout << "Model|";
    cout.width(15);
    cout << "Firm|";
    cout.width(15);
    cout << "Country|";
    cout.width(11);
    cout << "Cost|";
    cout.width(10);
    cout << "Style|";
    cout.width(13);
    cout << "Battery/";
    cout.width(13);
    cout << "Self wilding|";
    cout.width(10);
    cout << "Capacity/";
    cout.width(10);
    cout << "Skeleton|";
    cout << endl;
    cout
            << ("|----------|---------|--------------|--------------|----------|---------|-------------------------|-------------------|")
            << endl;
}

void menu::ending() {
    cout
            << ("|=====================================================================================================================|")
            << endl;
}

int menu::gettingPoint() {
    int point;
    cout << ("| Enter the number: ") << endl;
    cin >> point;
    return point;
}

void menu::finallyWriteToFile() {
    cout
            << ("|===================================================<Write_to_file>===================================================|")
            << endl << ("| Finally!") << endl;
    menu::ending();
}

void menu::finallyReadFromFile() {
    cout
            << ("|===================================================<Read_from_file>==================================================|")
            << endl << ("| Finally!") << endl;
    menu::ending();
}

void menu::showListMenu() {
    cout
            << ("|=======================================================<List>========================================================|")
            << endl;
    menu::showForm();

}

void menu::showSortMenu() {
    cout
            << ("|=====================================================<Sort_menu>=====================================================|")
            << endl;
    cout << ("| 1 - Sort by waterproof") << endl;
    cout << ("| 2 - Sort by cost") << endl;
    cout << ("| 3 - Sort by model") << endl;
    cout << ("| 4 - Sort by firm") << endl;
    cout << ("| 5 - Sort by country") << endl;
    cout << ("| 6 - Sort by style") << endl;
    menu::ending();
}

void menu::Finally() {
    cout << ("| Finally!") << endl;
    menu::ending();
}

char menu::getWay() {
    char way;
    cout << ("| Enter the way ('<' - from less to more; '>' - from more to less): ") << endl;
    cin >> way;
    return way;
}

void menu::addMenu() {
    cout
            << ("|===================================================<Link_inserting>==================================================|")
            << endl;
}

void menu::deleteMenu() {
    cout
            << ("|===================================================<Link_deleting>===================================================|")
            << endl;
}

void menu::showFindMenu() {
    cout
            << ("|=====================================================<Find_menu>=====================================================|")
            << endl;
    cout << ("| 1 - Find watches under 400USD") << endl;
    cout << ("| 2 - Find classic watches") << endl;
    cout << ("| 3 - Find watches from Switzerland with skeleton") << endl;
    menu::ending();
}

void menu::showDeletingMenu() {
    cout
            << ("|===================================================<List_deleting>===================================================|")
            << endl;
}

void menu::watchesUnder400(){
    cout
            << ("|================================================<Watch_under_400USD>=================================================|")
            << endl;
}

void menu::classicWatches(){
    cout
            << ("|==================================================<Classic_watches>==================================================|")
            << endl;
}

void menu::switzerlandWatchesWithSkeleton(){
    cout
            << ("|=========================================<Switzerland_watches_with_skeleton>=========================================|")
            << endl;
}

menu::~menu() = default;
