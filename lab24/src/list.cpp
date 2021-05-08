#include "list.h"

void list::setCount(const int countCopy)
{
	this->count = countCopy;
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

watch &list::ToClass(const string &obj) const
{
	string buffer = obj;
	string str;
	stringstream buf;
	int flag = 0;
	int pos = 0;
	auto *temp = new watch;
	int len = obj.length();
	for (int i = 0; i < len; ++i) {
		if (obj[i] == ' ') {
			if (flag == 0) {
				pos = buffer.find(' ');
				str = buffer.substr(0, pos);
				int LD;
				buf << str;
				buf >> LD;
				temp->setWaterproof(LD);
				buffer.erase(0, pos + 1);
				buf.clear();
				flag++;
				pos = i;
			} else if (flag == 1) {
				pos = buffer.find(' ');
				str = buffer.substr(0, pos);
				temp->setModel(str);
				buffer.erase(0, pos + 1);
				flag++;
			} else if (flag == 2) {
				pos = buffer.find(' ');
				str = buffer.substr(0, pos);
				int vol;
				buf << str;
				buf >> vol;
				temp->setCost(vol);
				buffer.erase(0, pos + 1);
				buf.clear();
				flag++;
			} else if (flag == 3) {
				for (int j = 0; j < buffer.length(); ++j) {
					if (buffer[j] == ' ') {
						pos = buffer.find(' ');
						string name = buffer.substr(0, pos);
						buffer.erase(0, pos + 1);
						pos = buffer.find(' ');
						string country = buffer.substr(0, pos);
						auto *firm = new manufacturerStruct(name, country);
						temp->setManufacturer(firm);
						break;
					}
					buf.clear();
					buffer.erase(0, pos + 1);
					flag++;
				}
			} else if (flag == 4) {
				//str = buffer.substr(0);

				pos = buffer.find(' ');
				str = buffer.substr(0, pos);
				int aim;
				buf << str;
				buf >> aim;
				switch (aim) {
				case 0:
					temp->setStyle(ARMOURED);
					break;
				case 1:
					temp->setStyle(CLASSIC);
					break;
				case 2:
					temp->setStyle(SPORT);
				default:
					break;
				}
				break;
			}
		}
	}

	return *temp;
}

void list::readFromFile(const string &sList)
{
	ifstream fileInf;
	fileInf.open(sList);
	string classL;

	this->setCount(3);
	delete[] this->watches;
	this->watches = new watch *[count + 1];
	if (!fileInf.is_open()) {
		cout << "Program can`t open the file!" << endl;
	} else {
		for (int i = 0; i < count; i++) {
			getline(fileInf, classL);
			this->watches[i] = &this->ToClass(classL);
		}
	}
	fileInf.close();
}