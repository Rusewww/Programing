//
// Created by Rusewww on 31.05.2021.
//

#include "menu.h"

void menu::showMainMenu() {
    cout
            << ("|=====================================================<Main_menu>=====================================================|")
            << endl;
    cout << ("|  1 - Show list") << endl;
    cout << ("|  2 - Write list to file") << endl;
    cout << ("|  3 - Read list from file") << endl;
    cout << ("|  4 - Sort by price ('<' - from less to more; '>' - from more to less)") << endl;
    cout << ("|  5 - Add link") << endl;
    cout << ("|  6 - Delete link") << endl;
    cout << ("|  7 - Find watches under 400USD") << endl;
    cout << ("|  8 - Find classic watches") << endl;
    cout << ("|  9 - Find watches from Switzerland with skeleton") << endl;
    cout << ("| 10 - Delete all list") << endl;
    cout << ("| 11 - Exit") << endl;
    cout
            << ("|=====================================================================================================================|")
            << endl;
}

void menu::showForm() {
    cout
            << ("|=======================================================<List>========================================================|")
            << endl;
    cout << "|";
    cout.width(10);
    cout << "Waterproof";
    cout.width(10);
    cout << "Model";
    cout.width(15);
    cout << "Firm";
    cout.width(15);
    cout << "Country";
    cout.width(10);
    cout << "Cost";
    cout.width(10);
    cout << "Style";
    cout.width(25);
    cout << "Battery/Self wilding";
    cout.width(20);
    cout << "Capacity/Skeleton";
    cout << endl;
}
