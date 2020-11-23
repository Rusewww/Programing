#include <stdlib.h>
#include <time.h>
/**
 * @file main.c Завдання 1 лабораторної роботи №5.
 *
 * Визначити найбільший спільний дільник для двох чисел.
 */

/**
 * @param rand_max - максисальне значення якого можуть набути числа;
 * @param a - перше число;
 * @param b - друге число;
 * @param div - НСД;
 */

/**
Функція main: формує 2 випадкових числа < 100, і передає їх до функції findGCF.
 */
int main() {
        srand(time(NULL));
        int rand_max = 100;
        const int a = rand() % rand_max + 1;
        const int b = rand() % rand_max + 1;
        int div;
        div = findGCF(b, a);
        return 0;
}
/**
Функція findGCF: визначає найбільший спільний дільник для двох заданих чисел і переставляє їх від більшого до меншого.
*/
int findGCF(int a, int b) {
        int remainder = 1;
        int divider;
        int num1;
        int num2;
        if (a > b) {
                num1 = a;
                num2 = b;
        }else{
                num1 = b;
                num2 = a;
        }
        while (remainder > 0) {
                remainder = num1 % num2;
                num1 = num2;
                num2 = remainder;
                if (remainder != 0) {
                        divider = remainder;
                }
        }
        return (divider);
}
