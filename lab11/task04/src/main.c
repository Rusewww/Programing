#include "lib.h"
#include <stdlib.h>

/**
 * @file main.c
 * @brief Дано масив. Елементи головної діагоналі виписати в окремий масив і впорядкувати за зростанням.
 * @author Зозуля Ігор.
 * @date 07-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву;
 * @param max - максимальне значення числа яке буде в масиві;
 * @param arr - заданий масив;
 * @param k - змінна для рахунку в ціклі ;
 * @param *one - заданий масив в лінійному вигляді ;
 * @param res - масив с результатом виконання програми ;
 */

/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              заповнює його випадковими числами, переписує у лінійний вигляд і передає
              все до функцій diagonal і sort_array.
*/

int main(){
        #define SIZE 4
        int max = 10;
        int arr[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                        arr[i][j] = rand() % max;
                }
        }
        int k = 0;
        int *one = (int*) malloc((SIZE * SIZE) * sizeof(int));
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++){
                        *(one + k) = arr[i][j];
                        k++;
                }
        }
        int res[SIZE];
        diagonal(SIZE, res, one);
        sort_array(SIZE, res);
        free(one);
        return 0;
}
