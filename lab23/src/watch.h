#ifndef PROGRAMING_WATCH_H
#define PROGRAMING_WATCH_H

#include <string>
#include <cstring>
#include <iostream>
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
	manufacturerStruct(string firm, string country);
	manufacturerStruct(const manufacturerStruct &copy);
	virtual ~manufacturerStruct();
};

class watch {
};

#endif //PROGRAMING_WATCH_H
