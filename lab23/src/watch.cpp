#include "watch.h"

#include <utility>

manufacturerStruct::manufacturerStruct()
{
	firm = "empty";
	country = "empty";
}

manufacturerStruct::manufacturerStruct(string firmClone, string countryClone)
{
	firm = std::move(firmClone);
	country = std::move(countryClone);
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

watch::watch()
{
	waterproof = false;
	model = "empty";
	cost = 0;
	watch::manufacturer = manufacturerStruct();
	style = ARMOURED;
}

watch::watch(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone, watchStyle styleClone)
{
	waterproof = waterproofClone;
	model = std::move(modelClone);
	cost = costClone;
	watch::manufacturer = manufacturerStruct(manufacturerClone);
	style = styleClone;
}

watch::watch(const watch &clone)
{
	waterproof = clone.waterproof;
	model = clone.model;
	cost = clone.cost;
	watch::manufacturer = manufacturerStruct(clone.manufacturer);
	style = clone.style;
}

watch::~watch() = default;

bool watch::getWaterproof() const
{
	return this->waterproof;
}

string watch::getModel() const
{
	return this->model;
}

int watch::getCost() const
{
	return this->cost;
}

manufacturerStruct watch::getManufacturer() const
{
	return this->manufacturer;
}

watchStyle watch::getStyle() const
{
	return this->style;
}

void watch::setWaterproof(const bool &waterproofClone)
{
	this->waterproof = waterproofClone;
}

void watch::setModel(const string &modelClone)
{
	this->model = modelClone;
}

void watch::setCost(const int &costClone)
{
	this->cost = costClone;
}

void watch::setManufacturer(manufacturerStruct *manufacturerClone)
{
	manufacturer.setFirm(manufacturerClone->getFirm());
	manufacturer.setCountry(manufacturerClone->getCountry());
}

void watch::setStyle(const watchStyle &styleClone)
{
	this->style = styleClone;
}

void watch::show()
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
	cout << endl;
}