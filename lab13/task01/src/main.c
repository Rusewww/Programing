//
// Created by Rusewww on 12/12/20.
//
#include <string.h>

int main() {
        #define SIZE 37
        char* arr  = (char*)malloc(SIZE * sizeof(char*));
        arr = strdup("This function can find count of words");
        int count = findCount(arr);
        return 0;
}
