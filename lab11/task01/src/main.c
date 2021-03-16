#include "lib.h"
#include <stdlib.h>

/**
 * @file main.c
 * @brief Дано масив. Визначити, чи є в масиві елементи, що повторюються, та відобразити результат в іншому масиві.
 * @author Зозуля Ігор.
 * @date 07-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву;
 * @param max - максимальне значення числа яке буде в масиві;
 * @param a - заданий масив;
 * @param ressize - розмір масиву з результатом ;
 * @param res - масив с результатом виконання програми ;
 */

/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              і передає все до функцій randomize, sizeCheck і findFrequency.
*/

int main () {
        #define SIZE 10
        int max = 100;
        int a[SIZE];
        randomize(a, SIZE, max);
        int ressize = sizeCheck(a, SIZE);
        int *res = (int*) malloc((unsigned int)ressize * sizeof(int));
        *res = 0;
        findFrequency(res, ressize, a, SIZE);
        free(res);
        return 0;
}
