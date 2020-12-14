//
// Created by Rusewww on 12/12/20.
//
#include "lib.h"
#include <string.h>
#include <malloc.h>

int main() {
        #define SIZE 37
        char* arr  = (char*)malloc(SIZE * sizeof(char*));
        arr = strdup("This function can find count of words");
        int count = findCount(arr);
        free(arr);
        return 0;
}
