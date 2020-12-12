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
 * @param array - заданий масив;
 * @param maxHead - координати початку максимальної послідовності ;
 * @param curHead - координати початку поточної послідовності ;
 * @param maxSum - сумма максимальної послідовності ;
 * @param curSum - сумма поточної послідовності ;
 * @param maxLength - довжина максимальної послідовності ;
 * @param curLength - довжина поточної послідовності ;
 */

/**
Функція randomizeWithMin: заповнює масив випадковими числами з відємними числами, які дорівнюють -max.
*/

#include <stdlib.h>
void randomizeWithMin(int arr[], int size, int max) {
        for (int i = 0; i < size; ++i) {
                arr[i] = (rand() % (max * 2) + 1) - max;
        }
}

/**
Функція findMaxHead: знаходить позицію першого елемента найбільшої послідовності.
*/

int findMaxHead(int array[], int size) {
        int maxHead = -1;
        int curHead = -1;
        int maxSum = 0;
        int curSum = 0;
        int maxLength = 0;
        int curLength = 0;
        for (int i = 0; i <= size; i++) {
                if (i == size || array[i] <= 0) {
                        if (curHead >= 0) {
                                if (curSum > maxSum) {
                                        maxHead = curHead;
                                        maxLength = curLength;
                                        maxSum = curSum;
                                }
                                curHead = -1;
                                curLength = 0;
                                curSum = 0;
                        }
                } else {
                        if (curHead < 0) {
                                curHead = i;
                        }
                        curLength += 1;
                        curSum += array[i];
                }
        }
        return (maxHead);
}

/**
Функція findMaxLength: дізнається довжину найбльщої послідовності.
*/

int findMaxLength(int array[], int size, int maxHead){
        int maxLength = 0;
        for (int i = maxHead; array[i] > 0; i++) {
                maxLength++;
        }
        return (maxLength);
}