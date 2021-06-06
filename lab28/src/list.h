#ifndef LAB28_LIST_H
#define LAB28_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::out_of_range;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::invalid_argument;
using std::move;

class list {
    string fileName;
    int count;
    int* sizes;
    int** arrays;
    int *result;
public:
    list();
    ~list();
    void readFromFile();
    void writeToFile();
    string getFileName() const;
    void setFileName(string FName);
    int *getResult();
    void setResult(int *res);
    int getSize(int arrIndex);
    int getElem(int arrIndex, int index);
    void setSize(int arrIndex, int val);
    void setElem(int arrIndex, int index, int val);
    int* findAverageValue();
};


#endif //LAB28_LIST_H
