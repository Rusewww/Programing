//
// Created by Rusewww on 28.05.2021.
//

#ifndef RGZ_WATCH_H
#define RGZ_WATCH_H

#include "controller.h"

enum watchStyle {
    ARMOURED, CLASSIC, SPORT
};
enum batteryType {
    GRAPHENE, LI_ION, SOLAR
};

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

    mechanicalWatches(bool waterproofClone, string modelClone, int costClone,
                      const manufacturerStruct &manufacturerClone, watchStyle styleClone,
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

    quartzWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone,
                  watchStyle styleClone,
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

bool operator==(watch &watch1, watch &watch2);
ostream &operator<<(ostream &output, quartzWatches &watch1);
istream &operator>>(istream &input, quartzWatches &watch1);
ostream &operator<<(ostream &output, mechanicalWatches &watch1);
istream &operator>>(istream &input, mechanicalWatches &watch1);

#endif //RGZ_WATCH_H
