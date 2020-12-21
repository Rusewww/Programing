#include "lib.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

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
        char* input = (char*)malloc(SIZE * sizeof(char*));
        char* key = (char*)malloc(1 * sizeof(char *));
        key = strdup(",");
        input = strdup("This function can find count of words");
        int count = findCount(input);
        free(arr);
        return 0;
}
