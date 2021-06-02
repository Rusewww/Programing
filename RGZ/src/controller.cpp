//
// Created by Rusewww on 28.05.2021.
//

#include "controller.h"


void controller::setList(list *watchListCopy) {
    this->watchList = *watchListCopy;
}

void controller::showList() const{
    watchList.showAll();
}

void controller::sortByCost(char way) {
    watchList.sortByCost(way);
}

watch *controller::findByPrice() {
    return watchList.findByPrice();
}

watch *controller::findClassicWatches() {
    return watchList.findClassicWatches();
}

watch *controller::findSwitzerlandWithSkeleton() {
    return watchList.findSwitzerlandWithSkeleton();
}
