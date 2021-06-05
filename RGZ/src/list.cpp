/**
 * @file list.cpp
 * @brief Код функцій задекларованих у list.h
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

vector<watch *> list::getList() const {
    return this->watches;
}

watch *list::getLink(int index) {
    return watches[(unsigned long) index];
}

void list::clearLink(int index) {
    if ((unsigned long) index > (unsigned long) watches.size()) {
        index = (int) watches.size();
    } else if (index < 0) {
        index = 0;
    }
    auto pos = watches.begin() + index;
    watches.erase(pos);
    this->count--;
}

void list::clearList() {
    while (!watches.empty()) {
        watches.pop_back();
    }
    watches.clear();
    watches.shrink_to_fit();
    this->count = 0;
}

void list::setLinks(const vector<watch *> &watchesCopy) {
    while (!watches.empty()) {
        watches.pop_back();
    }
    watches.clear();
    watches.shrink_to_fit();
    this->watches = watchesCopy;
}

list::list() = default;

list::~list() {
    while (!watches.empty()) {
        watches.pop_back();
    }
    watches.clear();
    watches.shrink_to_fit();
}
