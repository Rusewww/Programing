#ifndef RGZ_CONTROLLER_H
#define RGZ_CONTROLLER_H

#include "list.h"

class controller {
public:
    list watchList;

    controller();

    ~controller();

    void setList(list *watchListCopy);

    void showList() const;

    void sorting(char way, int criterion);

    vector<mechanicalWatches *> find(int criterion) const;

    bool readFromFile(const string &path);

    void writeToFile(const string &path);
};


#endif //RGZ_CONTROLLER_H
