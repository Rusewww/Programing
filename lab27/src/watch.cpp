/**
 * @file watch.cpp
 * @brief file of function declared in data.h
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

#include "watch.h"

#include <utility>

manufacturerStruct::manufacturerStruct()
{
	firm = "empty";
	country = "empty";
}

manufacturerStruct::manufacturerStruct(string firmClone, string countryClone)
{
	firm = move(firmClone);
	country = move(countryClone);
}

manufacturerStruct::manufacturerStruct(const manufacturerStruct &clone)
{
	firm = clone.firm;
	country = clone.country;
}

manufacturerStruct::~manufacturerStruct() = default;

string manufacturerStruct::getFirm() const
{
	return this->firm;
}

string manufacturerStruct::getCountry() const
{
	return this->country;
}

void manufacturerStruct::setFirm(const string &firmClone)
{
	this->firm = firmClone;
}

void manufacturerStruct::setCountry(const string &countryClone)
{
	this->country = countryClone;
}

void manufacturerStruct::showManufacturer()
{
	cout << "Manufacturer: " << firm << "; " << country << endl;
}

watch::~watch() = default;

mechanicalWatches::mechanicalWatches()
{
	waterproof = false;
	model = "empty";
	cost = 0;
	mechanicalWatches::manufacturer = manufacturerStruct();
	style = ARMOURED;
	selfWinding = false;
	skeleton = false;
}

mechanicalWatches::mechanicalWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone,
				     watchStyle styleClone, bool selfWindingClone, bool skeletonClone)
{
	waterproof = waterproofClone;
	model = move(modelClone);
	cost = costClone;
	mechanicalWatches::manufacturer = manufacturerStruct(manufacturerClone.getFirm(), manufacturerClone.getCountry());
	style = styleClone;
	selfWinding = selfWindingClone;
	skeleton = skeletonClone;
}
mechanicalWatches::mechanicalWatches(mechanicalWatches &clone)
{
	waterproof = clone.waterproof;
	model = clone.model;
	cost = clone.cost;
	manufacturer = clone.manufacturer;
	style = clone.style;
	selfWinding = clone.selfWinding;
	skeleton = clone.skeleton;
}
bool mechanicalWatches::getWaterproof()
{
	return this->waterproof;
}
string mechanicalWatches::getModel()
{
	return this->model;
}
int mechanicalWatches::getCost()
{
	return this->cost;
}
manufacturerStruct mechanicalWatches::getManufacturer()
{
	return this->manufacturer;
}
watchStyle mechanicalWatches::getStyle()
{
	return this->style;
}
void mechanicalWatches::setWaterproof(const bool &waterproofClone)
{
	this->waterproof = waterproofClone;
}
void mechanicalWatches::setModel(const string &modelClone)
{
	this->model = modelClone;
}
void mechanicalWatches::setCost(const int &costClone)
{
	this->cost = costClone;
}
void mechanicalWatches::setManufacturer(manufacturerStruct *manufacturerClone)
{
	this->manufacturer = *manufacturerClone;
}
void mechanicalWatches::setStyle(const watchStyle &styleClone)
{
	this->style = styleClone;
}
bool mechanicalWatches::getSelfWinding() const
{
	return this->selfWinding;
}
bool mechanicalWatches::getSkeleton() const
{
	return this->skeleton;
}
void mechanicalWatches::setSelfWinding(bool selfWindingClone)
{
	this->selfWinding = selfWindingClone;
}
void mechanicalWatches::setSkeleton(bool skeletonClone)
{
	this->skeleton = skeletonClone;
}
void mechanicalWatches::show()
{
	if (waterproof == 0) {
		cout << "Waterproof: No" << endl;
	} else {
		cout << "Waterproof: Have" << endl;
	}
	cout << "Model: " << model << endl;
	manufacturer.showManufacturer();
	cout << "Cost: " << cost << "USD" << endl;
	if (style == 0) {
		cout << "Style: Armoured" << endl;
	} else if (style == 1) {
		cout << "Style: Classic" << endl;
	} else {
		cout << "Style: Sport" << endl;
	}
	if (selfWinding) {
		cout << "Self winding: Have" << endl;
	} else {
		cout << "Self winding: No" << endl;
	}
	if (skeleton) {
		cout << "Skeleton: Have" << endl;
	} else {
		cout << "Skeleton: No" << endl;
	}
	cout << endl;
}
watch *mechanicalWatches::copy()
{
	return (watch *)new mechanicalWatches(*this);
}

mechanicalWatches::~mechanicalWatches() = default;
quartzWatches::quartzWatches()
{
	waterproof = false;
	model = "empty";
	cost = 0;
	quartzWatches::manufacturer = manufacturerStruct();
	style = ARMOURED;
	battery = GRAPHENE;
	capacity = 0;
}
quartzWatches::quartzWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone,
			     watchStyle styleClone, batteryType batteryClone, int capacityClone)
{
	waterproof = waterproofClone;
	model = move(modelClone);
	cost = costClone;
	quartzWatches::manufacturer = manufacturerStruct(manufacturerClone.getFirm(), manufacturerClone.getCountry());
	style = styleClone;
	battery = batteryClone;
	capacity = capacityClone;
}
quartzWatches::quartzWatches(quartzWatches &clone)
{
	waterproof = clone.waterproof;
	model = clone.model;
	cost = clone.cost;
	manufacturer = clone.manufacturer;
	style = clone.style;
	battery = clone.battery;
	capacity = clone.capacity;
}
bool quartzWatches::getWaterproof()
{
	return this->waterproof;
}
string quartzWatches::getModel()
{
	return this->model;
}
int quartzWatches::getCost()
{
	return this->cost;
}
manufacturerStruct quartzWatches::getManufacturer()
{
	return this->manufacturer;
}
watchStyle quartzWatches::getStyle()
{
	return this->style;
}
void quartzWatches::setWaterproof(const bool &waterproofClone)
{
	this->waterproof = waterproofClone;
}
void quartzWatches::setModel(const string &modelClone)
{
	this->model = modelClone;
}
void quartzWatches::setCost(const int &costClone)
{
	this->cost = costClone;
}
void quartzWatches::setManufacturer(manufacturerStruct *manufacturerClone)
{
	this->manufacturer = *manufacturerClone;
}
void quartzWatches::setStyle(const watchStyle &styleClone)
{
	this->style = styleClone;
}
batteryType quartzWatches::getBattery() const
{
	return this->battery;
}
int quartzWatches::getCapacity() const
{
	return this->capacity;
}
void quartzWatches::setBattery(batteryType batteryTypeClone)
{
	this->battery = batteryTypeClone;
}
void quartzWatches::setCapacity(int capacityClone)
{
	this->capacity = capacityClone;
}
void quartzWatches::show()
{
	if (waterproof == 0) {
		cout << "Waterproof: No" << endl;
	} else {
		cout << "Waterproof: Have" << endl;
	}
	cout << "Model: " << model << endl;
	manufacturer.showManufacturer();
	cout << "Cost: " << cost << "USD" << endl;
	if (style == 0) {
		cout << "Style: Armoured" << endl;
	} else if (style == 1) {
		cout << "Style: Classic" << endl;
	} else {
		cout << "Style: Sport" << endl;
	}
	if (battery == GRAPHENE) {
		cout << "Battery: Graphene" << endl;
	} else if (battery == LI_ION) {
		cout << "Battery: Li-Ion" << endl;
	} else {
		cout << "Battery: Solar" << endl;
	}
	cout << "Capacity: " << capacity << "mAh" << endl;
	cout << endl;
}
watch *quartzWatches::copy()
{
	return (watch *)new quartzWatches(*this);
}

quartzWatches::~quartzWatches() = default;
