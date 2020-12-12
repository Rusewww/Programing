/**
* @file lib.c
* @brief Реалізвція функцій для файлу main.c.
* @author Зозуля Ігор.
* @date 07-dec-2020
* @version 1.0
*/

/**
 * @param size - розміри масиву;
 * @param out - вихідний масив;
 * @param lone - заданий масив переведений в одномірний;
 * @param arr - вхідний масив ;
 * @param tmp - тимчасова змінна ;
 */

/**
Функція diagonal: переписує до масиву з результатом елементи головної діагоналі.
*/

void diagonal(int size, int out[], int *lone) {
        for (int i = 0; i < size; i++){
                out[i] = *(lone + ((i * size) + i));
        }
}

/**
Функція sort_array: сортує масив від маншого до більшого.
*/

void sort_array(int size, int arr[]){
        for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                                int tmp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = tmp;
                        }
                }
        }
}