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

void list::readFromFile(const string &file)
{
	ifstream fin;
	fin.open(file);
	string obj;
	if (fin.is_open()) {
		this->setCount(5);
		delete[] this->watches;
		fin >> *this;
	} else {
		cout << "Program can`t open the file!" << endl;
	}
	fin.close();
}

void list::writeToFile(const string &path) const
{
	ofstream file;
	file.open(path);

	if (file.is_open()) {
		file << *this;
	} else {
		cout << "Program can`t open the file!" << endl;
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
	if (index < (size_t)count) {
		return *watches[index];
	} else {
		return *watches[0];
	}
}

ostream &operator<<(ostream &out, const list &list1)
{
	for (size_t i = 0; i < (size_t)list1.getCount(); i++) {
		out << list1[i];
	}
	return out;
}

istream &operator>>(istream &in, list &list1)
{
	int count;
	cout << "Enter count: " << endl;
	cin >> count;
	list1.setCount(count);
	list1.watches = new watch *[count];
	for (size_t i = 0; i < (size_t)count; i++) {
		list1.watches[i] = new watch;
	}
	for (size_t i = 0; i < (size_t)count; i++) {
		cin >> list1[i];
	}
	return in;
}

ofstream &operator<<(ofstream &out, const list &list1)
{
	for (size_t i = 0; i < (size_t)list1.getCount(); ++i) {
		out << list1[i];
	}
	return out;
}

ifstream &operator>>(ifstream &in, list &list1)
{
	delete[] list1.watches;
	list1.watches = new watch *[list1.count];
	for (size_t i = 0; i <= (size_t)list1.count; ++i) {
		list1.watches[i] = new watch;
	}
	regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,6} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]*");
	for (size_t i = 0; i < (size_t)list1.getCount(); ++i) {
		int waterproof;
		in >> waterproof;
		string model;
		in >> model;
		int cost;
		in >> cost;
		int style;
		in >> style;
		string firm;
		in >> firm;
		string country;
		in >> country;
		stringstream str;
		str << waterproof << " " << model << " " << cost << " " << style << " " << firm << " " << country;
		if (regex_match(str.str(), reg)) {
			list1[i].setWaterproof(waterproof);
			list1[i].setModel(model);
			list1[i].setCost(cost);
			list1[i].setStyle((watchStyle)style);
			manufacturerStruct manufacturerC(firm, country);
			list1[i].setManufacturer(&manufacturerC);
		} else {
			cout << "Error:criterion entered incorrectly!" << endl;
		}
		str.str("");
	}
	return in;
}
