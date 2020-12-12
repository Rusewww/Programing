#include <malloc.h>
#include <stdlib.h>

/**
* @file lib.c
* @brief Реалізвція функцій для файлу main.c.
* @author Зозуля Ігор.
* @date 07-dec-2020
* @version 1.0
*/

/**
 * @param size - розміри масиву;
 * @param max - максимальне значення числа яке буде в масиві;
 * @param arr - заданий масив;
 * @param n - розмір пезультуючого масиву ;
 * @param cor - змінна для корекції результпату ;
 * @param result - результат виконання функцій ;
 */

/**
Функція randomize: заповнює масив випадковими числами.
*/

void randomize(int arr[], int size, int max) {
        for (int i = 0; i < size; i++) {
                arr[i] = rand() % max;
        }
}

/**
Функція sizeCheck: дізнається розмір результуючого масиву.
*/

int sizeCheck(int arr[], int size) {
        int n = size;
        for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                        if (arr[i] == arr[j]) {
                                n = n - 1;
                        }
                }
        }
        int result = n * 2;
        return (result);
}

/**
Функція findFrequency: знаходить частоту зустрічання певного елементу в масиві.
*/

void findFrequency(int* res, int n, int arr[], int size){
        int cor = 0;
        for (int i = 0; i < size; i++) {
                for (int k = 0; k < size; k++) {
                        for (int j = i - 1; j > 0; j--){
                                if (arr[j] == arr[i]) {
                                        i++;
                                        cor++;
                                }
                        }
                        if (arr[i] != arr[k]) {
                                *(res + (i - cor) * 2) = arr[i];
                        }else{
                                *(res + ((i - cor) * 2) + 1) += 1;
                        }
                }
        }
}