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
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::move;
using std::ofstream;
using std::ostream;
using std::regex;
using std::regex_match;
using std::stoi;
using std::string;
using std::stringstream;

enum watchStyle { ARMOURED, CLASSIC, SPORT };
enum batteryType { GRAPHENE, LI_ION, SOLAR };

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
    public:
	virtual bool getWaterproof() = 0;
	virtual string getModel() = 0;
	virtual int getCost() = 0;
	virtual manufacturerStruct getManufacturer() = 0;
	virtual watchStyle getStyle() = 0;
	virtual watch *copy() = 0;
	virtual void show() = 0;
	virtual ~watch();
};

class mechanicalWatches : public watch {
    private:
	bool waterproof{};
	string model;
	int cost{};
	manufacturerStruct manufacturer;
	watchStyle style;
	bool selfWinding{};
	bool skeleton{};

    public:
	mechanicalWatches();
	mechanicalWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone, watchStyle styleClone,
			  bool selfWindingClone, bool skeletonClone);
	mechanicalWatches(mechanicalWatches &clone);
	~mechanicalWatches() override;
	bool getWaterproof() override;
	string getModel() override;
	int getCost() override;
	manufacturerStruct getManufacturer() override;
	watchStyle getStyle() override;
	void setWaterproof(const bool &waterproofClone);
	void setModel(const string &modelClone);
	void setCost(const int &costClone);
	void setManufacturer(manufacturerStruct *manufacturerClone);
	void setStyle(const watchStyle &styleClone);
	bool getSelfWinding() const;
	bool getSkeleton() const;
	void setSelfWinding(bool selfWindingClone);
	void setSkeleton(bool skeletonClone);
	void show() override;
	watch *copy() override;
};

class quartzWatches : public watch {
    private:
	bool waterproof{};
	string model;
	int cost{};
	manufacturerStruct manufacturer;
	watchStyle style;
	batteryType battery;
	int capacity{};

    public:
	quartzWatches();
	quartzWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone, watchStyle styleClone,
		      batteryType batteryClone, int capacityClone);
	quartzWatches(quartzWatches &clone);
	~quartzWatches() override;
	bool getWaterproof() override;
	string getModel() override;
	int getCost() override;
	manufacturerStruct getManufacturer() override;
	watchStyle getStyle() override;
	void setWaterproof(const bool &waterproofClone);
	void setModel(const string &modelClone);
	void setCost(const int &costClone);
	void setManufacturer(manufacturerStruct *manufacturerClone);
	void setStyle(const watchStyle &styleClone);
	batteryType getBattery() const;
	int getCapacity() const;
	void setBattery(batteryType batteryTypeClone);
	void setCapacity(int capacityClone);
	void show() override;
	watch *copy() override;
};
#endif //PROGRAMING_WATCH_H
