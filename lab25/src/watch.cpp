/**
 * @file watch.cpp
 * @brief file of function declared in data.h
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

#include "watch.h"

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
	model = move(modelClone);
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

string watch::toString() const
{
	stringstream out;
	out << getWaterproof() << " " << getModel() << " " << getCost() << " " << getStyle() << " " << getManufacturer().getFirm() << " "
	    << getManufacturer().getCountry() << endl;
	return out.str();
}

watch watch::toClass(const string &sWatch)
{
	string clone = sWatch;
	unsigned long length = sWatch.length();
	string str;
	stringstream buffer;
	int counter = 0;
	unsigned long position = 0;
	watch tmp;
	for (unsigned long i = 0; i < length; i++) {
		if (sWatch[i] == ' ') {
			if (counter == 0) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				int waterproof;
				buffer << str;
				buffer >> waterproof;

				tmp.setWaterproof(waterproof);
				clone.erase(0, position + 1);
				buffer.clear();
				counter++;
				position = i;
			} else if (counter == 1) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				tmp.setModel(str);
				clone.erase(0, position + 1);
				counter++;
			} else if (counter == 2) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				int cost;
				buffer << str;
				buffer >> cost;
				tmp.setCost(cost);
				clone.erase(0, position + 1);
				buffer.clear();
				counter++;
			} else if (counter == 3) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				int style;
				buffer << str;
				buffer >> style;
				switch (style) {
				case 0:
					tmp.setStyle(ARMOURED);
					break;
				case 1:
					tmp.setStyle(CLASSIC);
					break;
				case 2:
					tmp.setStyle(SPORT);
				default:
					break;
				}
				buffer.clear();
				clone.erase(0, position + 1);
				counter++;
			} else if (counter == 4) {
				for (unsigned long j = 0; j < clone.length(); ++j) {
					if (clone[j] == ' ') {
						position = clone.find(' ');
						string firm = clone.substr(0, position);
						clone.erase(0, position + 1);
						string country = clone.substr(0, position);
						auto *manufacturer = new manufacturerStruct(firm, country);
						tmp.setManufacturer(manufacturer);
						delete manufacturer;
						break;
					}
				}
				break;
			}
		}
	}
	return tmp;
}
watch &watch::operator=(const watch &watch1)
{
	manufacturerStruct manufacturerClone;
	manufacturerClone.setFirm(watch1.getManufacturer().getFirm());
	manufacturerClone.setCountry(watch1.getManufacturer().getCountry());
	setManufacturer(&manufacturerClone);
	setWaterproof(watch1.getWaterproof());
	setCost(watch1.getCost());
	setModel(watch1.getModel());
	setStyle(watch1.getStyle());
	return *this;
}

bool operator==(watch &watch1, watch &watch2)
{
	if (watch1.getWaterproof() == watch2.getWaterproof() && watch1.getModel() == watch2.getModel() && watch1.getCost() == watch2.getCost() &&
	    watch1.getManufacturer().getCountry() == watch2.getManufacturer().getCountry() &&
	    watch1.getManufacturer().getFirm() == watch2.getManufacturer().getFirm() && watch1.getStyle() == watch2.getStyle()) {
		return true;
	} else {
		return false;
	}
}

ostream &operator<<(ostream &output, watch &watch1)
{
	output << watch1.getWaterproof() << ' ' << watch1.getModel() << ' ' << watch1.getCost() << ' ' << watch1.getManufacturer().getFirm() << ' '
	       << watch1.getManufacturer().getCountry() << ' ' << watch1.getStyle() << endl;
	return output;
}

istream &operator>>(istream &in, watch &watch1)
{
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
	stringstream buffer;
	buffer << waterproof << " " << model << " " << cost << " " << style << " " << firm << " " << country;
	regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]*");

	if (regex_match(buffer.str(), reg)) {
		watch1.setWaterproof(waterproof);
		watch1.setModel(model);
		watch1.setCost(cost);
		watch1.setStyle((watchStyle)style);
		manufacturerStruct manufacturerS(firm, country);
		watch1.setManufacturer(&manufacturerS);
		return in;
	} else {
		cout << "Error:criterion entered incorrectly!" << endl;
		in.clear();
		return in;
	}
}