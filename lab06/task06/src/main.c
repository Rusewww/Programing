#include <stdlib.h>
int main() {
        #define SIZE 3
        int max = 10;
        int a[SIZE][SIZE];
        int sqA[SIZE][SIZE];
        for (int i = 0; i <= SIZE; i++) {
                for (int j = 0; j <= SIZE; j++)
                     a[i][j] = rand() % max;
        }
        for(int i = 0; i < SIZE; i++) {
                for(int j = 0; j < SIZE; j++) {
                        sqA[i][j] = 0;
                        for(int c = 0; c < SIZE; c++) {
                                sqA[i][j] += a[i][c] * a[c][j];
                        }
                }
        }
        return 0;
}
