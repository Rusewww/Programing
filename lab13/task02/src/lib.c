#include <string.h>

/**
 * @file lib.c
 * @brief Реалізвція функцій для файлу main.c.
 * @author Зозуля Ігор.
 * @date 14-dec-2020
 * @version 1.0
 */

/**
 * @param SIZE - розміри масиву(кількість прізвищ);
 * @param arr - заданий масивв;
 */

/**
Функція deleteRepeat: видаляє прізвища які повторюються.
*/

int deleteRepeat(char** arr,int size){
        for(int i = 0; i < size; i++){
                for(int j = i + 1; j < size; j++){
                        if(! strcmp(arr[j], arr[i])){
                                arr[j] = arr[--size];
                                j--;
                        }
                }
        }
        return (size);
}
