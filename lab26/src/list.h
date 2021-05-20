#ifndef PROGRAMING_LIST_H
#define PROGRAMING_LIST_H

#include "watch.h"

class list {
    private:
	watch **watches{};
	int count{};

    public:
	virtual ~list();
	void setCount(int countCopy);
	int getCount() const;
	void addLink(watch watchLink);
	void removeLink(int index);
	watch &getLink(int index) const;
	void showAll() const;
	watch &findByPrice(int price) const;
	void writeToFile(const string &path) const;
	void deleteList();
	void readFromFile(const string &file);
	watch &operator[](size_t index) const;
	friend istream &operator>>(istream &input, list &list1);
	friend ostream &operator<<(ostream &output, const list &list1);
	friend ofstream &operator<<(ofstream &output, const list &list1);
	friend ifstream &operator>>(ifstream &input, list &list1);
};

istream &operator>>(istream &input, list &list1);
ostream &operator<<(ostream &output, const list &list1);
ofstream &operator<<(ofstream &output, const list &list1);
ifstream &operator>>(ifstream &input, list &list1);


#endif
