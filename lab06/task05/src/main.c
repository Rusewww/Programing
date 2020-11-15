#include <stdlib.h>
int main() {
        #define SIZE 4
        int a[SIZE][SIZE];
        int temp;
        for (int i = 0; i <= SIZE; i++){
                for (int j = 0; j <= SIZE; j++)
                     a[i][j] = rand() % 10;
        }
        for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++) {
                        if (j == 0) {
                                temp = a[i][j];
                                
                        }else{
                                a[i][j - 1] = a[i][j];
                        }
                        if (j ==  (SIZE - 1)) {
                                a[i][j] = temp;
                        }
                }
        }
        return 0;
}   
