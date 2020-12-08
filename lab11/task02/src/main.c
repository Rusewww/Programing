#include "lib.h"
#include <stdlib.h>

/**
 * @file main.c
 * @brief Дано масив. Знайти безперервну послідовність позитивних чисел. Послідовність з найбільшою суммною записати в масив.
 * @author Зозуля Ігор.
 * @date 07-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву;
 * @param max - максимальне значення числа яке буде в масиві;
 * @param array - заданий масив;
 * @param maxHead - координата першого єлементу потрібної послідовності ;
 * @param maxLeangth - довжина потрібної послідовності ;
 * @param *res - масив с результатом виконання програми ;
 */

/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              і передає все до функцій randomizeWithMin, findMaxHead і findMaxLength.
*/

int main() {
        #define SIZE 25
        int max = 20;
        int array[SIZE];
        randomizeWithMin(array, SIZE, max);
        int maxHead = findMaxHead(array, SIZE);
        int maxLength = findMaxLength(array, SIZE);
        int *res = (int*) malloc((unsigned int)maxLength * sizeof(int));
        for (int i = maxHead; i < maxHead + maxLength; i++ ) {
                *(res + i - maxHead) = array[i];
        }
        free(res);
        return 0;
}