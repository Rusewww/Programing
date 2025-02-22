/**
* @file watch.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 20-may-2021
* @version 1.0
*/

#ifndef PROGRAMING_WATCH_H
#define PROGRAMING_WATCH_H

#define SIZE 255

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
using std::ofstream;
using std::ostream;
using std::regex;
using std::regex_match;
using std::stoi;
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
    virtual void show();
    string toString() const;
    static watch toClass(const string &sWatch);
    watch &operator=(const watch &watch1);
};

bool operator==(watch &watch1, watch &watch2);
ostream &operator<<(ostream &output, watch &watch1);
istream &operator>>(istream &input, watch &watch1);

class mechanicalWatches : public watch {
private:
    bool selfWinding;
    bool skeleton;

public:
    mechanicalWatches();
    mechanicalWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone, watchStyle styleClone,
                      bool selfWindingClone, bool skeletonClone);
    mechanicalWatches(mechanicalWatches &clone);
    ~mechanicalWatches() override;
    bool getSelfWinding() const;
    bool getSkeleton() const;
    void setSelfWinding(bool selfWindingClone);
    void setSkeleton(bool skeletonClone);
    void show() override;
};

enum batteryType { GRAPHENE, LI_ION, SOLAR };

class quartzWatches : public watch {
private:
    batteryType battery;
    int capacity;

public:
    quartzWatches();
    quartzWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone, watchStyle styleClone,
                  batteryType batteryClone, int capacityClone);
    quartzWatches(quartzWatches &clone);
    ~quartzWatches() override;
    batteryType getBattery() const;
    int getCapacity() const;
    void setBattery(batteryType batteryTypeClone);
    void setCapacity(int capacityClone);
    void show() override;
};

bool operator>(const mechanicalWatches &one, const mechanicalWatches &two);

#endif //PROGRAMING_WATCH_H
