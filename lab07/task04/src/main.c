#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/**
Функція main: формує 1 випадкове число < 100, і передає його до функції perfect.
*/
int main() {
        srand(time(NULL));
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
