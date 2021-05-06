#ifndef PROGRAMING_WATCH_H
#define PROGRAMING_WATCH_H

#include <string>
#include <cstring>
#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::string;

enum watchStyle { ARMOURED, CLASSIC, SPORT };

class manufacturerStruct {
    private:
	string firm;
	string country;

    public:
	manufacturerStruct();
	manufacturerStruct(string firmClone, string countryClone);
	manufacturerStruct(const manufacturerStruct &clone);
	virtual ~manufacturerStruct();
};

class watch {
    private:
	bool waterproof;
	string model;
	int cost;
	manufacturerStruct manufacturer;
	watchStyle style;

    public:
	watch();
	watch(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct& manufacturerClone, watchStyle styleClone);
	watch(const watch &clone);
	virtual ~watch();
};

#endif //PROGRAMING_WATCH_H
