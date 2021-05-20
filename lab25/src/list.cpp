#include "list.h"

void list::setCount(const int countCopy)
{
	this->count = countCopy;
}

int list::getCount() const
{
	return this->count;
}

void list::addLink(watch watchLink)
{
	auto *tmp = new watch *[this->count + 2];
	for (int i = 0; i < this->count; i++) {
		tmp[i] = this->watches[i];
	}
	tmp[count] = &watchLink;
	delete[] this->watches;
	this->watches = tmp;
	this->count += 1;
}

void list::removeLink(int index)
{
	auto *tmp = new watch *[this->count];
	int fix = 0;
	if (index >= this->count) {
		index = this->count - 1;
	}
	for (int i = 0; i < this->count; i++) {
		if (i == index) {
			fix++;
		}
		tmp[i] = this->watches[i + fix];
	}
	delete[] this->watches;
	this->watches = tmp;
	this->count--;
}

watch &list::getLink(int index) const
{
	if (index >= this->count) {
		index = this->count - 1;
	}
	return *watches[index];
}

void list::showAll() const
{
	for (int i = 0; i < this->count; i++) {
		watch tmp = getLink(i);
		tmp.show();
	}
}

watch &list::findByPrice(const int price) const
{
	int index = 0;
	int countOfWatchUnder = 0;
	for (int i = 0; i < this->count; i++) {
		watch temp = getLink(i);
		if (price >= temp.getCost()) {
			temp.show();
			index = i;
			countOfWatchUnder++;
		}
	}
	if (countOfWatchUnder == 0) {
		cout << "There are no suitable watches!";
		return getLink(0);
	} else {
		return getLink(index);
	}
}

list::~list()
{
	delete[] watches;
}

void list::readFromFile(const string &sList)
{
	ifstream fileInf;
	fileInf.open(sList);
	string object;
	if (fileInf.is_open()) {
		delete[] this->watches;
		fileInf >> *this;
	} else {
		cout << "ERROR: The file did not open!";
	}
	fileInf.close();
}

void list::writeToFile(const string &path) const
{
	ofstream file;
	file.open(path);

	for (int i = 0; i < count; i++) {
		if (file.is_open()) {
			file << this->getLink(i).toString();
		} else {
			cout << "Program can`t open the file!" << endl;
		}
	}

	file.close();
}

void list::deleteList()
{
	delete[] this->watches;
	this->setCount(0);
	this->watches = new watch *[count];
}

watch &list::operator[](const size_t index) const
{
	if (index < count) {
		return *watches[index];
	} else {
		return *watches[0];
	}
}

ostream &operator<<(ostream &output, const list &list1)
{
	for (int i = 0; i < list1.getCount(); i++) {
		output << list1[i];
	}
	return output;
}

istream &operator>>(istream &input, list &list1)
{
	list1.watches = new watch *[list1.getCount()];
	for (int i = 0; i < list1.getCount(); ++i) {
		list1.watches[i] = new watch;
	}
	for (int i = 0; i < list1.getCount(); ++i) {
		cin >> list1[i];
	}
	return input;
}

ofstream &operator<<(ofstream &output, const list &list1)
{
	for (int i = 0; i < list1.getCount(); ++i) {
		output << list1[i];
	}
	return output;
}

ifstream &operator>>(ifstream &input, list &list1)
{
	delete[] list1.watches;
	list1.watches = new watch *[list1.count];
	for (int i = 0; i < list1.count; ++i) {
		list1.watches[i] = new watch;
	}
	bool waterproof;
	string model;
	int cost;
	string firm;
	string country;
	int style;
	stringstream str;
	stringstream buffer;
	regex regComp("^[0-1] [A-Z][a-z]* [0-9]{1,5} [a-zA-Z.&]* [A-Z][a-zA-Z] [0-2]*");
	for (int i = 0; i < list1.getCount(); ++i) {
		input >> waterproof;
		input >> model;
		input >> cost;
		input >> firm;
		input >> country;
		input >> style;

		str << ' ' << waterproof << ' ' << model << ' ' << cost << ' ' << firm << ' ' << country << ' ' << style;
		if (regex_match(buffer.str(), regComp)) {
			list1[i].setWaterproof(waterproof);
			list1[i].setModel(model);
			list1[i].setCost(cost);
			manufacturerStruct manufacturerClone(firm, country);
			list1[i].setManufacturer(&manufacturerClone);
			list1[i].setStyle((watchStyle)style);
		}
		buffer.str("");
	}

	return input;
}
