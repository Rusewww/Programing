#include "list.h"

#include <utility>

list::list() : fileName(), count(0), sizes(nullptr), arrays(nullptr), result(nullptr) {}

list::~list() {
    if (arrays)
        for (int i = 0; i < count; i++)
            delete[] arrays[i];
    delete[] arrays;
    delete[] sizes;
    delete[] result;
}

void list::readFromFile() {
    ifstream fin;
    fin.exceptions(ios_base::failbit | ios_base::badbit);
    fin.open(fileName, ios_base::in);
    fin >> count;
    if (count < 0) {
        throw invalid_argument("Invalid argument!");
    }
    sizes = new int[count];
    arrays = new int *[count];
    for (int i = 0; i < count; i++) {
        int val_size;
        fin >> val_size;
        setSize(i, val_size);
        arrays[i] = new int[getSize(i)];
        for (int j = 0; j < getSize(i); j++) {
            int val;
            fin >> val;
            setElem(i, j, val);
        }
    }
    fin.close();
}

void list::writeToFile() {
    ofstream FOut;
    FOut.exceptions(ios_base::failbit | ios_base::badbit);
    FOut.open(fileName, ios_base::out);
    for (int i = 0; i < count; i++) {
        FOut << result[i] << " ";
    }
    FOut.close();
}

int list::getSize(int arrIndex) {
    if (arrIndex >= count || arrIndex < 0) {
        throw out_of_range("Out of range exception");
    } else {
        return sizes[arrIndex];
    }
}

int list::getElem(int arrIndex, int index) {
    if (arrIndex >= count || arrIndex < 0) {
        throw out_of_range("Out of range exception");
    } else if (index >= sizes[arrIndex] || index < 0) {
        throw out_of_range("Out of range exception");
    } else {
        return arrays[arrIndex][index];
    }
}

void list::setSize(int arrIndex, int val) {
    if (arrIndex >= count || arrIndex < 0 || val < 0) {
        throw out_of_range("Out of range exception");
    } else {
        sizes[arrIndex] = val;
    }
}

void list::setElem(int arrIndex, int index, int val) {
    if (arrIndex >= count || arrIndex < 0) {
        throw out_of_range("Out of range exception:");
    } else if (index >= sizes[arrIndex] || index < 0) {
        throw out_of_range("Out of range exception");
    } else {
        arrays[arrIndex][index] = val;
    }
}

int *list::findAverageValue() {
    int *temp_res = new int[count];
    int sum;
    for (int i = 0; i < count; i++) {
        sum = 0;
        for (int j = 0; j < getSize(i); j++) {
            sum += getElem(i, j);
        }
        temp_res[i] = sum / getSize(i);
    }
    return temp_res;
}

string list::getFileName() const {
    return fileName;
}

void list::setFileName(string FName) {
    fileName = move(FName);
}

int *list::getResult() {
    return result;
}

void list::setResult(int *res) {
    result = res;
}

