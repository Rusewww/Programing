/**
* @file list.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 20-may-2021
* @version 1.0
*/

#ifndef PROGRAMING_LIST_H
#define PROGRAMING_LIST_H

#include "watch.h"

class list {
private:
    vector<watch *> watches{};
    int count{};

public:
    list();

    list(const list &clone);

    ~list();

    void setCount(int countCopy);

    int getCount() const;

    void addLink(watch *watchLink);

    watch *findByPrice();

    watch *findClassicWatches();

    watch *findSwitzerlandWithSkeleton();

    void showAll() const;

    void sortByCost(char way);

    void combineLists(list &in);
};

#endif
