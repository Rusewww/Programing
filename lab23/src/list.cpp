#include "list.h"

void list::setCount(const int countCopy)
{
	this->count = countCopy;
}

void list::addLink(watch &watchLink)
{
	auto **tmp = new watch *[this->count + 1];
	for (int i = 0; i < this->count; ++i) {
		tmp[i] = this->watches[i];
	}
	tmp[count] = &watchLink;
	delete[] this->watches;
	this->watches = tmp;
	this->count += 1;
}

void list::removeLink(int index)
{
	auto **tmp = new watch *[this->count - 1];

	if (index >= this->count) {
		index = this->count - 1;
	}

	memcpy(tmp, watches, sizeof(watch) * (index));
	memcpy(tmp + index, watches + index + 1, sizeof(watch) * (count - index));

	delete[] this->watches;
	this->watches = tmp;
	this->count -= 1;
}

watch &list::getLink(int index) const
{
	if (index >= this->count) {
		index = this->count - 1;
	}
	return *watches[index];
}

void list::showAll() const {
	for (int i = 0; i < this->count; ++i) {
		watch temp = getLink(i);
		temp.show();
	}
}

watch& list::findByPrice(const int price) const{
	int index = 0;
	int countOfWatchUnder = 0;
	for (int i = 0; i < this->count; ++i) {
		watch temp = getLink(i);
		if(price >= temp.getCost()){
			temp.show();
			index = i;
			countOfWatchUnder++;
		}
	}
	if(countOfWatchUnder == 0){
		cout << "here are no suitable watches!";
	} else {
		return getLink(index);
	}

}

list::~list(){
	for (int i = 0; i < this->count; ++i) {
		delete this->watches[i];
	}
	delete[] watches;

}