#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @file main.c
 * @brief Дано масив. Знайти безперервну послідовність де попереднє число менше наступного. Послідовність з найбільшою суммною записати в масив.
 * @author Зозуля Ігор.
 * @date 07-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву;
 * @param arr - заданий масив;
 * @param count - кількість послідовностей ;
 * @param maxLength - довжина потрібної послідовності ;
 * @param maxHead - номер останнього числа потрібної послідовності в заданому масиві ;
 * @param *res - результуючий масив
 */

/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              і передає все до функцій randomizeWithMin, findMaxHead і findMaxLength.
*/

int main() {
        #define SIZE 10
        double arr[SIZE] ={0.1, 0.5, 1, 0.2, 11.3, 10, 14.2, 15.5, 17, 0.7} ;
        int count = findCount(arr, SIZE);
        int maxLength = findLength(arr, SIZE);
        int maxHead = findHead(arr, SIZE);
        double *res = (double*) malloc((unsigned long)maxLength * sizeof(double));
        for (int i = ((maxHead - maxLength) + 1); i <= maxHead; i++ ) {
                *(res + (i - (maxHead - maxLength) - 1)) = arr[i];
        }
        free(res);
        return 0;
}
