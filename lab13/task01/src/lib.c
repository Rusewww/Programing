#include <string.h>

/**
* @file lib.c
* @brief Реалізвція функцій для файлу main.c.
* @author Зозуля Ігор.
* @date 14-dec-2020
* @version 1.0
*/

/**
 * @param arr - заданий масив;
 * @param count- кількість слів;
 * @param keys - ключ для виконання вункії;
 * @param phc - допомідний масив;
 */

/**
Функція findCount: знаходить кількість слів.
*/

int findCount(char * arr){
        char keys[] = {" "};
        int count = 0;
        char * phc = strtok(arr, keys);
        while (phc != NULL) {
                phc = strtok(NULL, keys);
                count++;
        }
        return count;
}
