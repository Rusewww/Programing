//
// Created by Rusewww on 31.05.2021.
//

#include "data.h"

void ShowMap(const map<string, set<string>> &map) {
    for_each(map.begin(), map.end(), [&](const pair<string, set<string>> &pair) {
        auto iter = pair.first;
        cout << "\t" << iter << ": ";
        for (const auto &elem: pair.second) {
            if (map.rbegin()->first == pair.first && pair.second.upper_bound(elem) == pair.second.end()) {
                cout << elem << ".";
            } else if (pair.second.upper_bound(elem) == pair.second.end()) {
                cout << elem << ";";
            } else {
                cout << elem << ", ";
            }
        }
        cout << endl;
    });
}

void fiveTask() {
    map<string, set<string>> mapOne, mapTwo, mapRes;

    mapOne = {{"Ukraine", {"Kharkov", "Kiev"}},
              {"Russia",  {"Moscow",  "Belgorod"}},
              {"Belarus", {"Minsk",   "Bobruisk"}},};

    mapTwo = {{"Poland",  {"Warsaw"}},
              {"Russia",  {"St.Petersburg"}},
              {"Ukraine", {"Kharkov", "Zaporozhye"}},};

    mapRes = mapOne;
    for_each(mapTwo.begin(), mapTwo.end(), [&](const pair<string, set<string>> &pair) {
        auto iter = mapRes.find(pair.first);
        if (iter == mapRes.end()) {
            mapRes.insert(pair);
        } else {
            iter->second.insert(pair.second.begin(), pair.second.end());
        }
    });
    cout << "First map:" << endl;
    ShowMap(mapOne);
    cout << endl;
    cout << "Second map:" << endl;
    ShowMap(mapTwo);
    cout << endl;
    cout << "Result map:" << endl;
    ShowMap(mapRes);
    cout << endl;

}