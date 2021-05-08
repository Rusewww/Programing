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
	out << getWaterproof() << " " << getModel() << " " << getCost() << " " << getManufacturer().getFirm() << " " << getManufacturer().getCountry()
	    << " " << getStyle() << endl;
	return out.str();
}

watch &watch::toClass(const string &sWatch)
{
	string clone = sWatch;
	unsigned int length = sWatch.length();
	string str;
	stringstream buffer;
	int counter = 0;
	unsigned int position = 0;
	auto *tmp = new watch;
	for (int i = 0; i < length; i++) {
		if (sWatch[i] == ' ') {
			if (counter == 0) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				int waterproof;
				buffer << str;
				buffer >> waterproof;
				tmp->setWaterproof(waterproof);
				clone.erase(0, position + 1);
				buffer.clear();
				position = i;
				counter++;
			} else if (counter == 1) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				tmp->setModel(str);
				clone.erase(0, position + 1);
				counter++;
			} else if (counter == 2) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				int cost;
				buffer << str;
				buffer >> cost;
				tmp->setCost(cost);
				clone.erase(0, position + 1);
				buffer.clear();
				counter++;
			} else if (counter == 3) {
				for (int j = 0; j < clone.length(); ++j) {
					if (clone[j] == ' ') {
						position = clone.find(' ');
						string firm = clone.substr(0, position);
						clone.erase(0, position + 1);
						string country = clone.substr(0, position + 1);
						auto *manufacturer = new manufacturerStruct(firm, country);
						tmp->setManufacturer(manufacturer);
						break;
					}
				}
				buffer.clear();
				clone.erase(0, position + 1);
				counter++;
			} else if (counter == 4) {
				position = clone.find(' ');
				str = clone.substr(0, position);
				int style;
				buffer << str;
				buffer >> style;
				switch (style) {
				case 0:
					tmp->setStyle(ARMOURED);
					break;
				case 1:
					tmp->setStyle(CLASSIC);
					break;
				case 2:
					tmp->setStyle(SPORT);
				default:
					break;
				}
			}
		}
	}
	return *tmp;
}