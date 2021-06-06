/**
 * @file list.cpp
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
    for (unsigned long i = 0; i < (unsigned long) count; i++) {
        watches[i] = clone.watches[i];
    }
}

void list::addLink(watch *watchLink) {
    this->watches.push_back(watchLink->copy());
    this->count++;
}

watch *list::getLink(int index) {
    return watches[(unsigned long) index];
}

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

vector<watch *> list::findByPrice() {
    vector<watch *> result;
    vector<watch *> tmp = this->watches;
    bool flag = true;
    auto iter = tmp.begin();
    while (true) {
        iter = find_if(iter, tmp.end(), findPriceHelp);
        if (iter == tmp.end()) {
            break;
        }
        flag = false;
        result.push_back((watch *) *iter);
        ((watch *) *iter)->show();
        cout << endl;
        iter++;
    }
    if (flag) {
        cout << "|There are no suitable watches!" << endl;
    }
    while (!tmp.empty()) {
        tmp.pop_back();
    }
    tmp.clear();
    tmp.shrink_to_fit();
    return result;
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

vector<watch *> list::findClassicWatches() {
    vector<watch *> result;
    vector<watch *> tmp = this->watches;
    bool flag = true;
    auto iter = tmp.begin();
    while (true) {
        iter = find_if(iter, tmp.end(), findClassicHelp);
        if (iter == tmp.end()) {
            break;
        }
        flag = false;
        result.push_back((watch *) *iter);
        ((watch *) *iter)->show();
        cout << endl;
        iter++;
    }
    if (flag) {
        cout << "|There are no suitable watches!" << endl;
    }
    while (!tmp.empty()) {
        tmp.pop_back();
    }
    tmp.clear();
    tmp.shrink_to_fit();
    return result;
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

vector<watch *> list::findSwitzerlandWithSkeleton() {
    vector<watch *> result;
    vector<watch *> tmp = this->watches;
    bool flag = true;
    auto iter = tmp.begin();
    while (true) {
        iter = find_if(iter, tmp.end(), findSwitzerlandWithSkeletonHelp);
        if (iter == tmp.end()) {
            break;
        }
        flag = false;
        result.push_back((watch *) *iter);
        ((watch *) *iter)->show();
        cout << endl;
        iter++;
    }
    if (flag) {
        cout << "|There are no suitable watches!" << endl;
    }
    while (!tmp.empty()) {
        tmp.pop_back();
    }
    tmp.clear();
    tmp.shrink_to_fit();
    return result;
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
    this->watches.reserve((unsigned long) this->count + (unsigned long) second.count);
    auto iter = this->watches.end();
    for (unsigned long i = 0; i < (unsigned long) second.count; ++i) {
        this->watches.insert(iter + (long) i, second.watches[i]);
    }
    this->count += second.count;

}

void list::showAll() const {
    for (unsigned long i = 0; i < (unsigned long) this->count; ++i) {
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
