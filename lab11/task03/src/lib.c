/**
* @file lib.c
* @brief Реалізвція функцій для файлу main.c.
* @author Зозуля Ігор.
* @date 07-dec-2020
* @version 1.0
*/

/**
Функція findCount: знаходить кількість необхідних послідовностей.
*/

int findCount(int arr[], int size) {
        int count = 0;
        int length = 1;
        int maxLength = 1;
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
                        count++;
                        f1 = 0;
                        f2 = 0;
                        head = i;
                        if (length > maxLength) {
                                maxLength = length;
                                length = 1;
                                maxHead = head;
                        }
                }
        }
        return(count);
}

/**
Функція findLength: знаходить довжину найбільшої послідовності.
*/

int findLength(int arr[], int size) {
        int count = 0;
        int length = 1;
        int maxLength = 1;
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
                        count++;
                        f1 = 0;
                        f2 = 0;
                        head = i;
                        if (length > maxLength) {
                                maxLength = length;
                                length = 1;
                                maxHead = head;
                        }
                }
        }
        return (maxLength);
}

/**
Функція findHead: знаходить позицію останнього елементу послідовності.
*/

int findHead(int arr[], int size) {
        int count = 0;
        int length = 1;
        int maxLength = 1;
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
                        count++;
                        f1 = 0;
                        f2 = 0;
                        head = i;
                        if (length > maxLength) {
                                maxLength = length;
                                length = 1;
                                maxHead = head;
                        }
                }
        }
        return (maxHead);
}
