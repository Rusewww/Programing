#include "lib.h"
#include <malloc.h>
#include <stdlib.h>

/**
 * @file main.c
 * @brief Дано масив. Визначити, чи є в масиві елементи, що повторюються, та відобразити результат в іншому масиві.
 * @author Зозуля Ігор.
 * @date 14-dec-2020
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
Функція main: задає масив та його розміри, і передає все до функцій randomizeLetter, sizeCheck і findFrequency.
*/

int main () {
    #define SIZE 10
    char a[SIZE];
    randomizeLetter(a, SIZE);
    int ressize = sizeCheck(a, SIZE);
    char *res = (char*) malloc((unsigned int)ressize * sizeof(char));
    *res = 0;
    findFrequency(res, ressize, a, SIZE);
    free(res);
    return 0;
}
