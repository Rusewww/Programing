#include "lib.h"
#include <string.h>
#include <stdlib.h>

/**
* @file main.c
* @brief Знайти числа в тексті.
* @author Зозуля Ігор.
* @date 14-dec-2020
* @version 1.0
*/

/**
 * @param SIZE - розміри масиву(кількість прізвищ);
 * @param input - заданий масив;
 * @param arr - допоміжний масив;
 * @param key - масив-ключ, для виконання функцій;
 * @param res - масив результату;
 */

/**
Функція main: задає масив, його розміри та значення і передає все до функції deleteRepeat у потрібному вигляді,
              після чого підготовлює данні для відображення у відладчику.
*/

int main(){
        int size = 7;
        char* input = (char*)malloc(((unsigned int)size * 10) * sizeof(char*));
        char** arr = (char**)malloc((unsigned int)size * sizeof(char*));
        char* key = (char*)malloc(10 * sizeof(char *));
        key = strdup(",");
        input = strdup("Macarenco,Zozulia,Klymenko,Macarenco,Gudzumanuk,Zuravlov,Klymenko");
        char* pch = (char*)malloc(((unsigned int)size * 10) * sizeof(char*));
        pch = strtok (input, key);
        int i = 0;
        while (pch != NULL){
                arr[i] = strdup(pch);
                pch = strtok(NULL, key);
                i++;
        }
        size = deleteRepeat(arr, size);
        char *res = (char*)malloc(((unsigned int)size * 10) * sizeof(char*));
        strcpy(res, arr[0]);
        strcat(res, key);
        for (i = 1; i < size; i++){
                strcat(res, arr[i]);
                if (i != size -1) {
                        strcat(res, key);
                }else{
                        strcat(res, "\0");
                }
        }
        for(i = 0; i < size; ++i) {
                free(arr[i]);
        }
        free(arr);
        free(res);
        free(input);
        free(pch);
        return 0;
}