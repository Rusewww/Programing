#include "lib.h"
#include <string.h>
#include <malloc.h>

int main(){
        int size = 7;
        char** arr  = (char**)malloc(size * sizeof(char*));
        arr[0] = strdup("Macarenco");
        arr[1] = strdup("Zozulia");
        arr[2] = strdup("Klymenko");
        arr[3] = strdup("Macarenco");
        arr[4] = strdup("Gudzumanuk");
        arr[5] = strdup("Zuravlov");
        arr[6] = strdup("Klymenko");
        size = deleteRepeat(arr, size);
        /*for(int i = 0; i < size; ++i) {
                puts(arr[i]);
        }*/
        for(int i = 0; i < size; ++i) {
                free(arr[i]);
        }
        free(arr);
        return 0;
}