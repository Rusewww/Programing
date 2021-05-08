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

/*watch list::toClass(const string &sWatch)
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
				position = i;
				counter++;
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
				for (unsigned long j = 0; j < clone.length(); ++j) {
					if (clone[j] == ' ') {
						position = clone.find(' ');
						string firm = clone.substr(0, position);
						clone.erase(0, position + 1);
						string country = clone.substr(0, position + 1);
						auto *manufacturer = new manufacturerStruct(firm, country);
						tmp.setManufacturer(manufacturer);
						delete manufacturer;
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
				break;
			}
		}
	}
	return tmp;
}*/

void list::readFromFile(const string &sList) {

	ifstream fileInf;
	fileInf.open(sList);
	string classL;

	this->setCount(3);
	delete [] this->watches;
	this->watches = new watch*[count + 1];
	for (int i = 0; i < 3; i++) {
		if (!fileInf.is_open()) {
			cout << "Program can`t open the file!" << endl;
		} else {
			auto *tmp = new watch;
			getline(fileInf, classL);
			*tmp = watch::toClass(classL);
			this->watches[i] = tmp;
			delete tmp;
			//this->watches[i] = ;
			//this->watches[i]->setCost(tmp.getCost());
		}
	}
	fileInf.close();
}