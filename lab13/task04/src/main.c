#include "lib.h"
#include <string.h>
#include <malloc.h>

/**
 * @file main.c
 * @brief Знайти числа в тексті.
 * @author Зозуля Ігор.
 * @date 14-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву(кількість прізвищ);
 * @param arr - заданий масив;
 * @param key - масив-ключ, для виконання функцій;
 * @param res - масив результату;
 */

/**
Функція main: задає масив, його розміри та значення і передає все до функції findNumb.
*/

int main(){
        #define SIZE 16
        char* arr = strdup("F1nd the nu6mb3rs");
        char* key = strdup("0123456789");
        int size = findLength(arr, key);
        int* res = (int*)malloc((unsigned int)size * sizeof(int*));
        findNumb(arr, key, res);
        free(arr);
        free(key);
        free(res);
        return 0;
}
