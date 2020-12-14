//
// Created by Rusewww on 12/13/20.
//

#include "lib.h"
#include <string.h>
#include <malloc.h>

int main(){
        #define SIZE 16
        char* arr  = (char*)malloc(SIZE * sizeof(char*));
        char* key  = (char*)malloc(10 * sizeof(char *));
        arr = strdup("F1nd1 the nu6mb3rs");
        key = strdup("0123456789");
        int size = findLength(arr, key);
        int* res  = (int*)malloc(size * sizeof(int*));
        findNumb(arr, key, res);
        free(arr);
        free(key);
        free(res);
        return  0;
}
