#include <stdlib.h>
#include <stdbool.h>
/**
 * @file main.c Завдання 4 лабораторної роботи №5.
 *
 * Визначте, чи є задане число досконалим (якщо воно дорівнює суммі воїх дільників).
 */

/**
 * @param rand_max - максисальне значення якого можуть набути числа;
 * @param num - число;
 * @param result - результат, чи є число досконалим;
 */
int perfect(int);
/**
Функція main: формує 1 випадкове число < 100, і передає його до функції perfect.
*/
int main() {
        int rand_max = 100;
        const int num = rand() % rand_max + 1;
        bool result = perfect(num);
        return 0;
}
/**
Функція perfect: визначає чи є задане число досконалим (якщо воно дорівнює суммі воїх дільників).
*/
int perfect(int num) {
        int sum = 0;
        bool perfect;
        for (int i = 1; i <= num / 2; i++) {
                if (num % i == 0) {
                          sum += i;
                }
        }
        //Перевірка на те, чи є число досконалим:
        if (sum == num) {
                perfect = true;
        }else{
                perfect = false;
        }
        return (perfect);
}
