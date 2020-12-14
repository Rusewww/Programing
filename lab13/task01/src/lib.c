//
// Created by Rusewww on 12/12/20.
//
#include <string.h>

int findCount(char * arr){
    char keys[] = {" "};
    int count = 0;
    char * phc = strtok(arr, keys);
    while (phc != NULL){
            phc = strtok(NULL, keys);
            count++;
    }
    return count;
}
