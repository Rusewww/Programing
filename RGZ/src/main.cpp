/**
 * @file main.cpp
 * @brief Код головної функції
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

#include "menu.h"

/**
 * main - головна функція программи
 * @return Код 0 - успышне виконання программи
 */

int main() {
    auto watchList = new list;
    auto Control = new controller;
    Control->setList(watchList);
    bool run = true;
    while (run) {
        menu::showMainMenu();
        int point = menu::gettingPoint();
        switch (point) {
            case 1:
                menu::showListMenu();
                Control->showList();
                menu::ending();
                break;
            case 2:
                Control->writeToFile("../dist/output.txt");
                menu::finallyWriteToFile();
                break;
            case 3:
                Control->readFromFile("../assets/input.txt");
                menu::finallyReadFromFile();
                break;
            case 4: {
                menu::showSortMenu();
                char way = menu::getWay();
                int pointSort = menu::gettingPoint();
                Control->sorting(way, pointSort);
                menu::Finally();
                break;
            }
            case 5: {
                menu::addMenu();
                char type;
                cout << ("| Enter type of watch(Q - quartz watches; M - mechanical watches): ") << endl;
                cin >> type;
                bool waterproof;
                string model;
                int cost;
                string firm;
                string country;
                int style;
                int filedOne;
                int filedTwo;
                stringstream buffer;
                regex regular(
                        "^[0-1] [A-Z][a-z]* [0-9]{1,5} [0-2] [A-Z][a-zA-Z]* [A-Z][a-zA-Z]* [0-2] [0-9]{1,3}$");
                switch (type) {
                    case 'Q':
                        cout << ("| Enter waterproof: ") << endl;
                        cin >> waterproof;
                        cout << ("| Enter model name: ") << endl;
                        cin >> model;
                        cout << ("| Enter cost: ") << endl;
                        cin >> cost;
                        cout << ("| Enter firm name: ") << endl;
                        cin >> firm;
                        cout << ("| Enter country: ") << endl;
                        cin >> country;
                        cout << ("| Enter style of watch: ") << endl;
                        cin >> style;
                        cout << ("| Enter battery type: ") << endl;
                        cin >> filedOne;
                        cout << ("| Enter capacity of battery: ") << endl;
                        cin >> filedTwo;
                        buffer << waterproof << " " << model << " " << cost << " " << style << " " << firm << " "
                               << country
                               << " "
                               << filedOne << " " << filedTwo;
                        if (regex_match(buffer.str(), regular)) {
                            quartzWatches watchAdd(waterproof, model, cost, manufacturerStruct(firm, country),
                                                   (watchStyle) style, (batteryType) filedOne, filedTwo);
                            Control->watchList.addLink(&watchAdd);
                        }
                        break;
                    case 'M':
                        cout << ("| Enter waterproof: ") << endl;
                        cin >> waterproof;
                        cout << ("| Enter model name: ") << endl;
                        cin >> model;
                        cout << ("| Enter cost: ") << endl;
                        cin >> cost;
                        cout << ("| Enter firm name: ") << endl;
                        cin >> firm;
                        cout << ("| Enter country: ") << endl;
                        cin >> country;
                        cout << ("| Enter style of watch: ") << endl;
                        cin >> style;;
                        cout << ("| Enter self wilding: ") << endl;
                        cin >> filedOne;
                        cout << ("| Enter skeleton: ") << endl;
                        cin >> filedTwo;
                        buffer << waterproof << " " << model << " " << cost << " " << style << " " << firm << " "
                               << country
                               << " "
                               << filedOne << " " << filedTwo;
                        if (regex_match(buffer.str(), regular)) {
                            mechanicalWatches watchAdd(waterproof, model, cost, manufacturerStruct(firm, country),
                                                       (watchStyle) style, (batteryType) filedOne, filedTwo);
                            Control->watchList.addLink(&watchAdd);
                            menu::Finally();
                        } else {
                            cout << ("| Some criterion entered incorrectly!!!") << endl;
                            menu::ending();
                        }
                        break;
                    default:
                        cout << ("| Incorrect variant!!!") << endl;
                        menu::ending();
                        break;
                }
                break;
            }
            case 6: {
                menu::deleteMenu();
                int index = menu::gettingPoint();
                Control->watchList.deleteLink(index);
                menu::Finally();
                break;
            }
            case 7: {
                menu::showFindMenu();
                int criterion = menu::gettingPoint();
                switch (criterion) {
                    case 1:
                        menu::watchesUnder400();
                        break;
                    case 2:
                        menu::classicWatches();
                        break;
                    case 3:
                        menu::switzerlandWatchesWithSkeleton();
                        break;
                    default:
                        cout << ("| Criterion entered incorrectly!!!") << endl;
                }
                menu::showForm();
                Control->find(criterion);
                break;
            }
            case 8:
                menu::showDeletingMenu();
                Control->watchList.clearList();
                menu::Finally();
                menu::ending();
                break;
            case 9:
                run = false;
                break;
            default:
                cout << ("| Incorrect variant!!!") << endl;
                menu::ending();
        }
    }
    delete Control;
    delete watchList;
    return 0;
}
