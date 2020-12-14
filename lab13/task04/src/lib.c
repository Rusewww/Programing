//
// Created by Rusewww on 12/13/20.
//
#include <string.h>
#include <malloc.h>
int findLength(char *arr, char *key){
        int size = 0;
        char * pch = strpbrk (arr, key);
        while (pch != NULL){
            size ++;
            pch = strpbrk (pch+1, key);
        }
        return size;
}

void findNumb(char *arr, char *key, int *res){
        char * pch = strpbrk (arr, key);
        int i = 0;
        while (pch != NULL){
                *(res + i) = (*pch - 48);
                pch = strpbrk (pch+1, key);
                i++;
        }
}