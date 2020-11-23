#include <stdlib.h>
#include <time.h>
/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              і заповнює його випадковими числами, і передає все до функції sq_array.
*/
int main () {
        srand(time(NULL));
        #define SIZE 3 //Розміри масивів
        int max = 10; //Максимальне значення числа яке буде занесено в масив
        int a[SIZE][SIZE]; //Заданий масив
        int sqA[SIZE][SIZE]; //Масив помножений на себе
        //Заповнення масиву випадковими числами
        for (int i = 0; i <= SIZE; i++) {
                for (int j = 0; j <= SIZE; j++)
                     a[i][j] = rand() % (max + 1);
        }
        sq_array(SIZE, a, sqA);
        return 0;
}
/**
Функція sq_array: множить вхідний масив сам на себе, за правилами множення матриць.
*/
void sq_array(int SSIZE, int a[][SSIZE], int sqA[][SSIZE]) {
        for(int i = 0; i < SSIZE; i++) {
               for(int j = 0; j < SSIZE; j++) {
                       sqA[i][j] = 0;
                       for(int c = 0; c < SSIZE; c++) {
                               sqA[i][j] += a[i][c] * a[c][j];
                       }
               }
       }
}
