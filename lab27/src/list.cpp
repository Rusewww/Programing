#include "list.h"

void list::setCount(const int countCopy)
{
	this->count = countCopy;
}

int list::getCount() const
{
	return this->count;
}
list::list(const list &clone)
{
	for (int i = 0; i < count; i++) {
		watches[i] = clone.watches[i];
	}
}
void list::addLink(watch *watchLink)
{
	auto *tmp = new watch *[this->count + 2];
	for (int i = 0; i < this->count; i++) {
		tmp[i] = this->watches[i];
	}
	tmp[count] = watchLink;
	delete[] this->watches;
	this->watches = tmp;
	this->count += 1;
}
watch *list::getLink(int index) const
{
	if (index >= this->count) {
		index = this->count - 1;
	}
	return watches[index];
}

watch *list::findByPrice(int price) const
{
	int index = 0;
	int countOfWatchUnder = 0;
	for (int i = 0; i < this->count; i++) {
		auto *temp = getLink(i);
		if (price >= temp->getCost()) {
			temp->show();
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
watch *list::findClassicWatches() const
{
	int index = 0;
	int countOfWatch = 0;
	for (int i = 0; i < this->count; i++) {
		auto *temp = getLink((int)i);
		if (CLASSIC == temp->getStyle()) {
			temp->show();
			index = (int)i;
			countOfWatch++;
		}
	}
	if (countOfWatch == 0) {
		cout << "There are no suitable watches!" << endl;
		return getLink(0);
	} else {
		return getLink(index);
	}
}
watch *list::findSwitzerlandWithSkeleton() const
{
	int index = 0;
	int countOfWatch = 0;
	for (int i = 0; i < this->count; i++) {
		auto *temp = (mechanicalWatches *)getLink((int)i);
		if (temp->getSkeleton() && temp->getManufacturer().getCountry() == "Switzerland") {
			temp->show();
			index = (int)i;
			countOfWatch++;
		}
	}
	if (countOfWatch == 0) {
		cout << "There are no suitable watches!" << endl;
		return getLink(0);
	} else {
		return getLink(index);
	}
}
void list::showAll() const
{
	for (int i = 0; i < this->count; ++i) {
		watches[i]->show();
		cout << endl;
	}
}

list::list() = default;
list::~list() = default;
