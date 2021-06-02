//
// Created by Rusewww on 28.05.2021.
//

#ifndef RGZ_CONTROLLER_H
#define RGZ_CONTROLLER_H

#include "list.h"

class controller {
private:
    list watchList;
public:
    void setList(list *watchListCopy);

    void showList() const;

    void sortByCost(char way);

    watch *findByPrice();

    watch *findClassicWatches();

    watch *findSwitzerlandWithSkeleton();
};


#endif //RGZ_CONTROLLER_H
