#include "watch.h"

#ifndef RGZ_LIST_H
#define RGZ_LIST_H


class list {
private:
    vector<watch *> watches;
    int count{};
public:
    list();

    list(const list &clone);

    ~list();

    void setCount(int countCopy);

    int getCount() const;

    void addLink(watch *watchLink);

    vector<watch*> getLink() const;

    watch *getLink(int index);

    void clearLink(int index);

    void clearList();

    void showAll() const;

    void setLinks(const vector<watch *>& watchesCopy);
};

#endif //RGZ_LIST_H
