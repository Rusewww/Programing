#include "lib.h"
#include <stdlib.h>
int main() {
        #define SIZE 25
        int max = 20;
        int array[SIZE];
        randomizeWithMin(array, SIZE, max);
        int maxHead = findMaxHead(array, SIZE);
        int maxLength = findMaxLenght(array, SIZE);
        int *res = (int*) malloc(maxLength * sizeof(int));
        for (int i = maxHead; i < maxHead + maxLength; i++ ) {
                *(res + i - maxHead) = array[i];
        }
        return 0;
}