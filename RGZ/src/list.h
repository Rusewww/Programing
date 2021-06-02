//
// Created by Rusewww on 28.05.2021.
//

#include "watch.h"

#ifndef RGZ_LIST_H
#define RGZ_LIST_H


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

    void sortByCost(char way);

    watch *getLink(int index);

    void clearLink(int index);

    void clearList();

    void showAll() const;
};

#endif //RGZ_LIST_H
