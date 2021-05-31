/**
 * @file lib.cpp
 * @brief file of function declared in list.h
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

#include "list.h"

void list::setCount(const int countCopy) {
    this->count = countCopy;
}

int list::getCount() const {
    return this->count;
}

list::list(const list &clone) {
    for (int i = 0; i < count; i++) {
        watches[i] = clone.watches[i];
    }
}

void list::addLink(watch *watchLink) {
    this->watches.push_back(watchLink->copy());
    this->count++;
}
/*watch *list::getLink(int index) const
{
    if (index >= this->count) {
        index = this->count - 1;
    }
    return watches[index];
}*/

/*watch *list::findByPrice(int price) const
{
    int index = 0;
    int countOfWatchUnder = 0;
    for (int i = 0; i < this->count; i++) {
        auto *temp = watches[i];
        if (price >= temp->getCost()) {
            temp->show();
            index = i;
            countOfWatchUnder++;
        }
    }
    if (countOfWatchUnder == 0) {
        cout << "There are no suitable watches!";
        return watches[0];
    } else {
        return watches[index];
    }
}*/

bool findPriceHelp(watch *one) {
    auto *temp = (watch *) one->copy();
    if (temp->getCost() <= 400) {
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

watch *list::findByPrice() {
    watch *res;
    bool flag = true;
    auto iter = watches.begin();
    for (; iter != watches.end(); iter++) {
        iter = find_if(iter, this->watches.end(), findPriceHelp);
        flag = false;
        ((watch *) *iter)->show();
        cout << endl;
    }
    if (flag) {
        cout << "There are no suitable watches!" << endl;
    }
    res = (watch *) *iter;
    return res;
}

bool findClassicHelp(watch *one) {
    auto *temp = (watch *) one->copy();
    if (temp->getStyle() == CLASSIC) {
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

watch *list::findClassicWatches() {
    watch *res;
    bool flag = true;
    auto iter = watches.begin();
    for (; iter != watches.end(); iter++) {
        iter = find_if(iter, this->watches.end(), findClassicHelp);
        flag = false;
        ((watch *) *iter)->show();
        cout << endl;
    }
    if (flag) {
        cout << "There are no suitable watches!" << endl;
    }
    res = (watch *) *iter;
    return res;
}

bool findSwitzerlandWithSkeletonHelp(watch *one) {
    auto *temp = (mechanicalWatches *) one->copy();
    if (temp->getManufacturer().getCountry() == "Switzerland" && temp->getSkeleton()) {
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

watch *list::findSwitzerlandWithSkeleton() {
    watch *res;
    bool flag = true;
    auto iter = watches.begin();
    for (; iter != watches.end(); iter++) {
        iter = find_if(iter, this->watches.end(), findSwitzerlandWithSkeletonHelp);
        flag = false;
        ((watch *) *iter)->show();
        cout << endl;
    }
    if (flag) {
        cout << "There are no suitable watches!" << endl;
    }
    res = (watch *) *iter;
    return res;
}

bool functorLess(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getCost() > tempTwo->getCost()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

bool functorMore(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getCost() < tempTwo->getCost()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

void list::sortByCost(char way) {
    if (way == '<') {
        sort(watches.begin(), watches.end(), functorMore);
    } else {
        sort(watches.begin(), watches.end(), functorLess);
    }
}

void list::combineLists(list &second) {
    this->watches.reserve(this->count + second.count);
    auto iter = this->watches.end();
    for (int i = 0; i < second.count; ++i) {
        this->watches.insert(iter + i, second.watches[i]);
    }
    this->count += second.count;

}

void list::showAll() const {
    for (int i = 0; i < this->count; ++i) {
        watches[i]->show();
        cout << endl;
    }
}

list::list() = default;

list::~list() {
    while (!watches.empty()) {
        watches.pop_back();
    }
    watches.clear();
    watches.shrink_to_fit();
}
