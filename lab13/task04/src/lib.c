#include <string.h>
#include <malloc.h>

/**
 * @file lib.c
 * @brief Реалізвція функцій для файлу main.c.
 * @author Зозуля Ігор.
 * @date 14-dec-2020
 * @version 1.0
 */

/**
 * @param size - розміри масиву;
 * @param arr - заданий масив;
 * @param key - масив-ключ, для виконання функцій;
 * @param pch - допоміжний масив;
 * @param res - масив результату;
 * @param arr - заданий масивв;
 */

/**
Функція findLength: знаходить довжину масиву.
*/

int findLength(char *arr, char *key){
        int size = 0;
        char * pch = strpbrk (arr, key);
        while (pch != NULL){
            size ++;
            pch = strpbrk (pch+1, key);
        }
        return size;
}

/**
Функція findNumb: знаходить числа які зустрічаються в тексті.
*/

void findNumb(char *arr, char *key, int *res){
        char * pch = strpbrk (arr, key);
        int i = 0;
        while (pch != NULL){
                *(res + i) = (*pch - 48);
                pch = strpbrk (pch+1, key);
                i++;
        }
}