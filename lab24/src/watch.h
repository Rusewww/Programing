/**
* @file watch.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 20-may-2021
* @version 1.0
*/

#ifndef PROGRAMING_WATCH_H
#define PROGRAMING_WATCH_H

#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <sstream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

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
	string getFirm() const;
	string getCountry() const;
	void setFirm(const string &firmClone);
	void setCountry(const string &countryClone);
	void showManufacturer();
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
	watch(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone, watchStyle styleClone);
	watch(const watch &clone);
	virtual ~watch();
	bool getWaterproof() const;
	string getModel() const;
	int getCost() const;
	manufacturerStruct getManufacturer() const;
	watchStyle getStyle() const;
	void setWaterproof(const bool &waterproofClone);
	void setModel(const string &modelClone);
	void setCost(const int &costClone);
	void setManufacturer(manufacturerStruct *manufacturerClone);
	void setStyle(const watchStyle &styleClone);
	void show();
	string toString() const;
	static watch toClass(const string &sWatch);
};

#endif //PROGRAMING_WATCH_H
