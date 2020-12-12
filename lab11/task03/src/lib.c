/**
* @file lib.c
* @brief Реалізвція функцій для файлу main.c.
* @author Зозуля Ігор.
* @date 07-dec-2020
* @version 1.0
*/

/**
 * @param size - розміри масиву;
 * @param a - заданий масив;
 * @param f1 - допоміжна змінна №1 ;
 * @param f2 - допоміжна змінна №2 ;
 * @param count - кількість послідовностей ;
 * @param head - номер останнього числа поточної послідовності в заданому масиві ;
 * @param maxHead - номер останнього числа потрібної послідовності в заданому масиві ;
 * @param maxLength - довжина максимальної послідовності ;
 * @param length - довжина поточної послідовності ;
 */

/**
Функція findCount: знаходить кількість необхідних послідовностей.
*/

int findCount(double arr[], int size) {
    int count = 0;
    int f = 0;
    int f2 = 0;
    for(int i = 0; i < size; i ++) {
            if(arr[i] < arr[i+1]) {
                    f = 1;
            }else if(arr[i] > arr[i + 1]){
                    f2 = 1;
            }
            if(f == 1 && f2 == 1) {
                    count ++;
                    f = 0;
                    f2 = 0;
            }
    }
    return(count);
}

/**
Функція findLength: знаходить довжину найбільшої послідовності.
*/

int findLength(double arr[], int size) {
        int length = 0;
        int maxLength = 0;
        int f1 = 0;
        int f2 = 0;
        for (int i = 0; i < size; i++) {
                if (arr[i] < arr[i + 1]) {
                        f1 = 1;
                        length++;
                }else{
                        f2 = 1;
                }
                if (f1 == 1 && f2 == 1) {
                        f1 = 0;
                        f2 = 0;
                        if (length > maxLength) {
                                maxLength = length;
                                length = 0;
                        }
                }
        }
        return (maxLength);
}

/**
Функція findHead: знаходить позицію останнього елементу послідовності.
*/

int findHead(double arr[], int size) {
        int length = 0;
        int maxLength = 0;
        int head = 0;
        int maxHead = 0;
        int f1 = 0;
        int f2 = 0;
        for (int i = 0; i < size; i++) {
                if (arr[i] < arr[i + 1]) {
                        f1 = 1;
                        length++;
                }else{
                        f2 = 1;
                }
                if (f1 == 1 && f2 == 1) {
                        f1 = 0;
                        f2 = 0;
                        head = i;
                        if (length > maxLength) {
                                maxLength = length;
                                length = 0;
                                maxHead = head;
                        }
                }
        }
        return (maxHead);
}