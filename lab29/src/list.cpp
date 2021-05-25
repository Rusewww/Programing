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

string &list::readFromFile(const string &sList, string classL[3])
{
	ifstream fileInf;
	fileInf.open(sList);
	int length = 3;
	for (int i = 0; i < length; i++) {
		getline(fileInf, classL[i]);
	}
	fileInf.close();
	return *classL;
}

void list::writeToFile(const string &path) const
{
	ofstream file;
	file.open(path);

	for (int i = 0; i < count; ++i) {
		if (file.is_open()) {
			file << this->getLink(i).toString();
		} else {
			cout << "Program can`t open the file!" << endl;
		}
	}

	file.close();
}

void list::deleteList() {
	delete[] this->watches;
	this->setCount(0);
	this->watches = new watch * [count];
}

/*#ifndef LAB23_LIST_HPP
#define LAB23_LIST_HPP

#include "Backpack.h"

template <typename Type>
class List{
    Type *elements[ARRAY_SIZE];
    int index = 0;
public:
    List() {}


    virtual ~List() = default; // {
//        while (index >= 0){
//            delete elements[index];
//            index--;
//        }
//    }

    void addElement( Type * element ){
        //index += 1;
        if (index >= 255) {
            return;
        }
        elements[index] = element;
        index += 1;
    }


    Type& getElement (int index) const {
        if (index < 0) {
            index = 0;
        }
        if (index >= this->index) {
            index = this->index - 1;
        }

        return *elements[index];
    }

    void deleteElement(int index){
        if (index < 0) {
            index = 0;
        }
        if (index >= this->index) {
            index = this->index - 1;
        }
        for (int i = index; i < this->index; ++i) {
            elements[i] = elements[i+1];
        }
        this->index--;
    }

    Type& FindMinElement(){
        this->SortList();
        return *elements[0];
    }

    int FindIndexElement(Type &element){
        int result = -1;
        for (int i = 0; i < index; ++i) {
            if (*elements[i] == element){
                result = i;
            }
        }
        return result;
    };

    void ShowList() const{
        for (int i = 0; i < this->index; ++i) {
            cout << *elements[i] << endl;
        }
    }

    void SortList(){
        for(int i = 0; i < index; i++){
            for(int j = 0; j < index - 1; j++){
                if (*elements[j] > *elements[j + 1]){
                    Type temp = *elements[j];
                    *elements[j] = *elements[j +1];
                    *elements[j +1] = temp;
                }
            }
        }
    }

};


#endif*/