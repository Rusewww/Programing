/**
 * @file list.hpp
 * @brief file of function of list
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

#ifndef LAB29_LIST_HPP
#define LAB29_LIST_HPP

#include "watch.h"

template <typename Type>
class list{
    Type *elements[SIZE];
    int index = 0;
public:
    list() = default;


    virtual ~list()  {
        int i = 0;
        while (i < index){
            delete elements[index - 1];
            i++;
        }
        index = 0;
    }

    void addLink( Type * element ){
        if (index >= 255) {
            return;
        }
        elements[index] = element;
        index += 1;
    }


    Type& getLink (int index) const {
        if (index < 0) {
            index = 0;
        }
        if (index >= this->index) {
            index = this->index - 1;
        }

        return *elements[index];
    }

    void deleteLink(int index){
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

    Type& findMinLink(){
        this->sortList();
        return *elements[0];
    }

    int findIndexLink(Type &element){
        int result = -1;
        for (int i = 0; i < index; ++i) {
            if (*elements[i] == element){
                result = i;
            }
        }
        return result;
    };

    void showList() const{
        for (int i = 0; i < this->index; ++i) {
            cout << *elements[i] << endl;
        }
    }

    void sortList(){
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

#endif //LAB29_LIST_HPP
