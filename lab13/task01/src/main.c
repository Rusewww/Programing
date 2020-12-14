#include "lib.h"
#include <string.h>
#include <malloc.h>

/**
 * @file main.c
 * @brief Визначити кількість слів без іттераціі по кожному символу.
 * @author Зозуля Ігор.
 * @date 14-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву;
 * @param arr - заданий масив;
 * @param count- кількість слів;
 */

/**
Функція main: задає масив, його розміри та значення і передає все до функції findCount.
*/

int main() {
        #define SIZE 37
        char* arr = (char*)malloc(SIZE * sizeof(char*));
        arr = strdup("This function can find count of words");
        int count = findCount(arr);
        free(arr);
        return 0;
}
