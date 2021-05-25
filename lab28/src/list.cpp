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

/*#include "Task.h"


Task::Task() : fileName(), TaskNumber(0), Count(0), sizes(nullptr), arrays(nullptr), ResultSize(0), result(nullptr) {}

Task::~Task() {
    if (arrays)
        for (int i = 0; i < Count; i++)
            delete[] arrays[i];
    delete[] arrays;
    delete[] sizes;
    delete[] result;
}

void Task::Run() {
    for (;;) {
        try {
            cout << "Enter Input FileName: ";
            ReadFileName();
            if (fileName == "\\exit") // \\exit => "\exit"
                return;
            cout << "Reading... " <<endl;
            ReadFromFile();
            TaskNumber = Menu();
            CallingSelectedFunction(TaskNumber);
            cout << endl << "Enter Output FileName: ";
            ReadFileName();
            if (fileName == "\\exit")
                return;
            cout << "Writing... " << endl;
            WriteToFile();
        }
        catch (out_of_range& e) {
            cout << e.what() << endl;
        }
        catch (std::ios_base::failure& e) {
            cout << e.what() << endl;
        }
        catch (std::invalid_argument& e) {
            cout << e.what() << endl;
        }
        cout << endl << "-----------------------------------------" << endl << endl;
        //system("pause&cls");
    }
}

void Task::ReadFileName() {
    cin >> fileName;
}

void Task::ReadFromFile() {
    ifstream fin;
    fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fin.open(fileName, std::ios_base::in);
    fin >> Count;
    if (Count < 0) {
        throw std::invalid_argument("Bad Argument");
    }
    sizes = new int[Count];
    arrays = new int*[Count];
    for (int i = 0; i < Count; i++) {
        int val_size;
        fin >> val_size;
        setSize(i, val_size);
        arrays[i] = new int[getSize(i)];
        for (int j = 0; j < getSize(i); j++)
        {
            int val;
            fin >> val;
            setElem(i, j, val);
        }
    }
    fin.close();
}

void Task:: WriteToFile() {
    ofstream fout;
    fout.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fout.open(fileName, std::ios_base::out);
    for (int i = 0; i < ResultSize; i++){
        fout << result[i] << " ";
    }
    fout.close();
}

int Task:: getSize(int arrIndex) {
    if (arrIndex >= Count || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return sizes[arrIndex];
    }
}
int Task:: getElem(int arrIndex, int index) {
    if (arrIndex >= Count || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return arrays[arrIndex][index];
    }
}
void Task:: setSize(int arrIndex, int val) {
    if (arrIndex >= Count || arrIndex < 0 || val < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        sizes[arrIndex] = val;
    }
}
void Task:: setElem(int arrIndex, int index, int val) {
    if (arrIndex >= Count || arrIndex < 0 ){
        throw out_of_range("Out of range exception:");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        arrays[arrIndex][index] = val;
    }
}

int* Task::SumArrays(int index1, int index2){
    if (getSize(index1) != getSize(index2)) {
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    ResultSize = getSize(index1);
    int *temp_res = new int[ResultSize];
    for (int i = 0; i < ResultSize; i++)
        temp_res[i] = getElem(index1, i) + getElem(index2, i);
    return temp_res;
}

int* Task::MultiplyArrays(int index1, int index2) {
    if (getSize(index1) != getSize(index2)) {
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    ResultSize = getSize(index1);
    int *temp_res = new int[ResultSize];
    for (int i = 0; i < ResultSize; i++)
        temp_res[i] = getElem(index1, i) * getElem(index2, i);
    return temp_res;
}

int* Task::CalcAverage() {
    int *temp_res = new int[Count];
    int sum = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            sum += getElem(i, j);
        }
        temp_res[i] = sum / getSize(i);
        sum = 0;
    }
    return temp_res;
}

int* Task::FindMaxElem(){
    int *temp_res = new int[Count];
    int elem = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

int* Task::FindMinElem(){
    int *temp_res = new int[Count];
    int elem = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem > getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

int* Task::FindPositiveNumber() {
    int *temp_res = new int[Count];
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) >= 0){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Task::SearchInRange(int range1, int range2) {
    if(range1 >= range2){
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    int *temp_res = new int[Count];
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) >= range1 && getElem(i, j) <= range2) {
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Task::FindNegativeNumber() {
    int *temp_res = new int[Count];
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) < 0){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Task::FindMaxElemPos(){
    int *temp_res = new int[Count];
    int pos = 0;
    int elem = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
                pos = j;
            }
        }
        temp_res[i] = pos;
    }
    return temp_res;
}

int* Task::FindCountMaxElem() {
    int *temp_res = new int[Count];
    int elem = 0;
    int count = 0;
    ResultSize = Count;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        for (int j = 0; j < getSize(i); ++j) {
            if(elem == getElem(i, j)){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

void Task::ForTest(int number){
    fileName = "test.txt";
    TaskNumber = number;
    ReadFromFile();
    CallingSelectedFunction(TaskNumber);
    fileName = "TestResult.txt";
    WriteToFile();
}*/