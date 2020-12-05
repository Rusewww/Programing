#include "lib.h"
#include <malloc.h>
#include <stdlib.h>
int main () {
        #define SIZE 10
        int max = 100;
        int a[SIZE];
        randomize(a, SIZE, max);
        int ressize = sizeCheck(a, SIZE);
        int *res = (int*) malloc(ressize * sizeof(int));
        *res = 0;
        findFrequency(res, ressize, a, SIZE);
        free(res);
        return 0;
}
