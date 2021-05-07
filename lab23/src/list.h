#ifndef PROGRAMING_LIST_H
#define PROGRAMING_LIST_H

#include "watch.h"

class list {
    private:
	watch **watches;
	int count;

    public:
	virtual ~list();
	void setCount(int countCopy);
	void addLink(watch watchLink);
	void removeLink(int index);
	watch &getLink(int index) const;
	void showAll() const;
	watch &findByPrice(int price) const;
};

#endif //PROGRAMING_LIST_H
