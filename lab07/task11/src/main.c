#include <stdlib.h>
#include <time.h>
/**
 * @file main.c Завдання 6 лабораторної роботи №6.
 *
 * Дано масив. Потрібно помножити його сам на себе по правилу множення матриць.
 */

/**
* @param SIZE - розміри масиву;
 * @param max - максимальне значення числа яке буде в масиві;
 * @param a - заданий масив;
 * @param sqA - заданий масив помножений на себе ;

 */

/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              і заповнює його випадковими числами, і передає все до функції sq_array.
*/
int main () {
        srand(time(NULL));
        #define SIZE 3
        int max = 10;
        int a[SIZE][SIZE];
        int sqA[SIZE][SIZE];
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
