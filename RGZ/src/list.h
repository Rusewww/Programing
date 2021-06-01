//
// Created by Rusewww on 28.05.2021.
//

#include "controller.h"

#ifndef RGZ_LIST_H
#define RGZ_LIST_H


class list {
private:
    watch **watches{};
    int count{};

public:
    list();
    list(const list &clone);
    ~list();
    void setCount(int countCopy);
    int getCount() const;
    void addLink(watch *watchLink);
    watch *getLink(int index) const;
    watch *findByPrice(int price) const;
    watch *findClassicWatches() const;
    watch *findSwitzerlandWithSkeleton() const;
    void showAll() const;
};

#endif //RGZ_LIST_H
