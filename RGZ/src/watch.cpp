/**
 * @file watch.cpp
 * @brief Код функцій задекларованих у watch.h
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */


#include "watch.h"

manufacturerStruct::manufacturerStruct() {
    firm = "empty";
    country = "empty";
}

manufacturerStruct::manufacturerStruct(string firmClone, string countryClone) {
    firm = move(firmClone);
    country = move(countryClone);
}

manufacturerStruct::manufacturerStruct(const manufacturerStruct &clone) {
    firm = clone.firm;
    country = clone.country;
}

manufacturerStruct::~manufacturerStruct() = default;

string manufacturerStruct::getFirm() const {
    return this->firm;
}

string manufacturerStruct::getCountry() const {
    return this->country;
}

void manufacturerStruct::setFirm(const string &firmClone) {
    this->firm = firmClone;
}

void manufacturerStruct::setCountry(const string &countryClone) {
    this->country = countryClone;
}

void manufacturerStruct::showManufacturer() {
    cout.width(14);
    cout << firm << "|";
    cout.width(14);
    cout << country << "|";
}

watch::~watch() = default;

mechanicalWatches::mechanicalWatches() {
    waterproof = false;
    model = "empty";
    cost = 0;
    mechanicalWatches::manufacturer = manufacturerStruct();
    style = ARMOURED;
    selfWinding = false;
    skeleton = false;
}

mechanicalWatches::mechanicalWatches(bool waterproofClone, string modelClone, int costClone,
                                     const manufacturerStruct &manufacturerClone,
                                     watchStyle styleClone, bool selfWindingClone, bool skeletonClone) {
    waterproof = waterproofClone;
    model = move(modelClone);
    cost = costClone;
    mechanicalWatches::manufacturer = manufacturerStruct(manufacturerClone.getFirm(), manufacturerClone.getCountry());
    style = styleClone;
    selfWinding = selfWindingClone;
    skeleton = skeletonClone;
}

mechanicalWatches::mechanicalWatches(mechanicalWatches &clone) {
    waterproof = clone.waterproof;
    model = clone.model;
    cost = clone.cost;
    manufacturer = clone.manufacturer;
    style = clone.style;
    selfWinding = clone.selfWinding;
    skeleton = clone.skeleton;
}

bool mechanicalWatches::getWaterproof() {
    return this->waterproof;
}

string mechanicalWatches::getModel() {
    return this->model;
}

int mechanicalWatches::getCost() {
    return this->cost;
}

manufacturerStruct mechanicalWatches::getManufacturer() {
    return this->manufacturer;
}

watchStyle mechanicalWatches::getStyle() {
    return this->style;
}

void mechanicalWatches::setWaterproof(const bool &waterproofClone) {
    this->waterproof = waterproofClone;
}

void mechanicalWatches::setModel(const string &modelClone) {
    this->model = modelClone;
}

void mechanicalWatches::setCost(const int &costClone) {
    this->cost = costClone;
}

void mechanicalWatches::setManufacturer(manufacturerStruct *manufacturerClone) {
    this->manufacturer = *manufacturerClone;
}

void mechanicalWatches::setStyle(const watchStyle &styleClone) {
    this->style = styleClone;
}

bool mechanicalWatches::getSelfWinding() const {
    return this->selfWinding;
}

bool mechanicalWatches::getSkeleton() const {
    return this->skeleton;
}

void mechanicalWatches::setSelfWinding(bool selfWindingClone) {
    this->selfWinding = selfWindingClone;
}

void mechanicalWatches::setSkeleton(bool skeletonClone) {
    this->skeleton = skeletonClone;
}

void mechanicalWatches::show() {
    cout << "|";
    if (waterproof == 0) {
        cout.width(11);
        cout << "No|";
    } else {
        cout.width(11);
        cout << "Have|";
    }
    cout.width(9);
    cout << model << "|";
    manufacturer.showManufacturer();
    cout.width(7);
    cout << cost;
    cout.width(4);
    cout << "USD|";
    if (style == 0) {
        cout.width(10);
        cout << "Armoured|";
    } else if (style == 1) {
        cout.width(10);
        cout << "Classic|";
    } else {
        cout.width(10);
        cout << "Sport|";
    }
    if (selfWinding) {
        cout.width(26);
        cout << "Have|";
    } else {
        cout.width(26);
        cout << "No|";
    }
    if (skeleton) {
        cout.width(20);
        cout << "Have|";
    } else {
        cout.width(20);
        cout << "No|";
    }
}

watch *mechanicalWatches::copy() {
    return (watch *) new mechanicalWatches(*this);
}

mechanicalWatches::~mechanicalWatches() = default;

quartzWatches::quartzWatches() {
    waterproof = false;
    model = "empty";
    cost = 0;
    quartzWatches::manufacturer = manufacturerStruct();
    style = ARMOURED;
    battery = GRAPHENE;
    capacity = 0;
}

quartzWatches::quartzWatches(bool waterproofClone, string modelClone, int costClone,
                             const manufacturerStruct &manufacturerClone,
                             watchStyle styleClone, batteryType batteryClone, int capacityClone) {
    waterproof = waterproofClone;
    model = move(modelClone);
    cost = costClone;
    quartzWatches::manufacturer = manufacturerStruct(manufacturerClone.getFirm(), manufacturerClone.getCountry());
    style = styleClone;
    battery = batteryClone;
    capacity = capacityClone;
}

quartzWatches::quartzWatches(quartzWatches &clone) {
    waterproof = clone.waterproof;
    model = clone.model;
    cost = clone.cost;
    manufacturer = clone.manufacturer;
    style = clone.style;
    battery = clone.battery;
    capacity = clone.capacity;
}

bool quartzWatches::getWaterproof() {
    return this->waterproof;
}

string quartzWatches::getModel() {
    return this->model;
}

int quartzWatches::getCost() {
    return this->cost;
}

manufacturerStruct quartzWatches::getManufacturer() {
    return this->manufacturer;
}

watchStyle quartzWatches::getStyle() {
    return this->style;
}

void quartzWatches::setWaterproof(const bool &waterproofClone) {
    this->waterproof = waterproofClone;
}

void quartzWatches::setModel(const string &modelClone) {
    this->model = modelClone;
}

void quartzWatches::setCost(const int &costClone) {
    this->cost = costClone;
}

void quartzWatches::setManufacturer(manufacturerStruct *manufacturerClone) {
    this->manufacturer = *manufacturerClone;
}

void quartzWatches::setStyle(const watchStyle &styleClone) {
    this->style = styleClone;
}

batteryType quartzWatches::getBattery() const {
    return this->battery;
}

int quartzWatches::getCapacity() const {
    return this->capacity;
}

void quartzWatches::setBattery(batteryType batteryTypeClone) {
    this->battery = batteryTypeClone;
}

void quartzWatches::setCapacity(int capacityClone) {
    this->capacity = capacityClone;
}

void quartzWatches::show() {
    cout << "|";
    if (waterproof == 0) {
        cout.width(11);
        cout << "No|";
    } else {
        cout.width(11);
        cout << "Have|";
    }
    cout.width(9);
    cout << model << "|";
    manufacturer.showManufacturer();
    cout.width(7);
    cout << cost;
    cout.width(4);
    cout << "USD|";
    if (style == 0) {
        cout.width(10);
        cout << "Armoured|";
    } else if (style == 1) {
        cout.width(10);
        cout << "Classic|";
    } else {
        cout.width(10);
        cout << "Sport|";
    }
    if (battery == GRAPHENE) {
        cout.width(12);
        cout << "Graphene";
        cout.width(14);
        cout << "|";
    } else if (battery == LI_ION) {
        cout.width(12);
        cout << "Li-Ion";
        cout.width(14);
        cout << "|";
    } else {
        cout.width(12);
        cout << "Solar";
        cout.width(14);
        cout << "|";
    }
    cout.width(6);
    cout << capacity;
    cout.width(3);
    cout << "mAh";
    cout.width(11);
    cout << "|";
}

watch *quartzWatches::copy() {
    return (watch *) new quartzWatches(*this);
}

quartzWatches::~quartzWatches() = default;

bool operator==(watch &watch1, watch &watch2) {
    if (watch1.getWaterproof() == watch2.getWaterproof() && watch1.getModel() == watch2.getModel() &&
        watch1.getCost() == watch2.getCost() &&
        watch1.getManufacturer().getCountry() == watch2.getManufacturer().getCountry() &&
        watch1.getManufacturer().getFirm() == watch2.getManufacturer().getFirm() &&
        watch1.getStyle() == watch2.getStyle()) {
        return true;
    } else {
        return false;
    }
}

ostream &operator<<(ostream &output, quartzWatches &watch1) {
    output << watch1.getWaterproof() << ' ' << watch1.getModel() << ' ' << watch1.getCost() << ' '
           << watch1.getManufacturer().getFirm() << ' '
           << watch1.getManufacturer().getCountry() << ' ' << watch1.getStyle() << ' ' << watch1.getBattery() << ' '
           << watch1.getCapacity() << endl;
    return output;
}

istream &operator>>(istream &in, quartzWatches &watch1) {
    cout << "Enter the data: " << endl;
    cout << "Waterproof(0 - No; 1 - Have): " << endl;
    bool waterproof;
    in >> waterproof;
    cout << "Model: " << endl;
    string model;
    in >> model;
    cout << "Cost: " << endl;
    int cost;
    in >> cost;
    cout << "Firm: " << endl;
    string firm;
    in >> firm;
    cout << "Country: " << endl;
    string country;
    in >> country;
    cout << "Style(0 - Armoured; 1 - Classic; 2 - Sport): " << endl;
    int style;
    in >> style;
    cout << "Battery(0 - Graphene; 1 - Li_Ion; 2 - Solar): " << endl;
    int battery;
    in >> battery;
    cout << "Enter capacity: " << endl;
    int capacity;
    in >> capacity;
    watch1.setWaterproof(waterproof);
    watch1.setModel(model);
    watch1.setCost(cost);
    watch1.setStyle((watchStyle) style);
    manufacturerStruct manufacturerS(firm, country);
    watch1.setManufacturer(&manufacturerS);
    watch1.setBattery((batteryType) battery);
    watch1.setCapacity(capacity);
    return in;

}

ostream &operator<<(ostream &output, mechanicalWatches &watch1) {
    output << watch1.getWaterproof() << ' ' << watch1.getModel() << ' ' << watch1.getCost() << ' '
           << watch1.getManufacturer().getFirm() << ' '
           << watch1.getManufacturer().getCountry() << ' ' << watch1.getStyle() << ' ' << watch1.getSelfWinding() << ' '
           << watch1.getSkeleton() << endl;
    return output;
}

istream &operator>>(istream &in, mechanicalWatches &watch1) {
    cout << "Enter the data: " << endl;
    cout << "Waterproof(0 - No; 1 - Have): " << endl;
    bool waterproof;
    in >> waterproof;
    cout << "Model: " << endl;
    string model;
    in >> model;
    cout << "Cost: " << endl;
    int cost;
    in >> cost;
    cout << "Firm: " << endl;
    string firm;
    in >> firm;
    cout << "Country: " << endl;
    string country;
    in >> country;
    cout << "Style(0 - Armoured; 1 - Classic; 2 - Sport): " << endl;
    int style;
    in >> style;
    cout << "Self winding(0 - No; 1 - Have): " << endl;
    int SelfWinding;
    in >> SelfWinding;
    cout << "Skeleton(0 - No; 1 - Have): " << endl;
    int Skeleton;
    in >> Skeleton;
    watch1.setWaterproof(waterproof);
    watch1.setModel(model);
    watch1.setCost(cost);
    watch1.setStyle((watchStyle) style);
    manufacturerStruct manufacturerS(firm, country);
    watch1.setManufacturer(&manufacturerS);
    watch1.setSelfWinding(SelfWinding);
    watch1.setSkeleton(Skeleton);
    return in;

}
