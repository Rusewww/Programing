#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
/**
 * @file main.c Завдання 2 лабораторної роботи №6.
 *
 * Заповнити масив із заданої кількості елементів простими числами що не повторюються.
 */

/**
 * @param max - максимальне значення числа для запису в масив;
 * @param a - массив;
 * @param FSIZE - розмір масиву;
 */

/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розмір, і передає все до функції fill_prime.
*/
int main(){
        #define FSIZE 10
        int a[FSIZE];
        int max = 100;
        fill_prime(FSIZE, a, max);
        return 0;
}
/**
Функція fill_prime: заповнює масив випадковими натуральними числами.
*/
void fill_prime(int SIZE, int a[], int max) {
        srand(time(NULL));
        int num;
        if (SIZE > max / 4) {
                for (int i = 0; i < SIZE; i++) {
                        a[i] = 0;
                }
        }else{
                for (int i = 0; i < SIZE; i++) {
                        bool primeNum;
                        do {
                                num = rand() % max;
                                primeNum = true;
                                //Проверка на повторяемость
                                for (int i2 = 0; i2 < i; i2++) {
                                        if (num == a[i2]) {
                                                primeNum = false;
                                                break;
                                        }
                                }
                                if (num == 1) {
                                        primeNum = false;
                                }else if (num == 2){
                                        primeNum = true;
                                }else if (num % 2 == 0) {
                                        primeNum = false;
                                }else{
                                        for (int i3 = 3; i3 < num; i3 += 2) {
                                                if(num % i3 == 0){
                                                        primeNum = false;
                                                        break;
                                                }
                                        }
                                }
                        }while (primeNum == false);
                        a[i] = num;
                }
        }
}
