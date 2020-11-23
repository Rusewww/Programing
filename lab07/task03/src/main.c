#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/**
Функція main: формує 1 випадкове число > 100000, але < 999999 і передає його до функції prime_num.
*/
int main() {
        srand(time(NULL));
        const int num = rand() % (999999 - 100000 + 1) + 100000;
        bool result = lucky(num);
        return 0 ;
}
/**
Функція lucky: перевіряє число на те, счасливе воно, чи ні.
*/
int lucky(int num) {
        int sum1 = 0;
        int sum2 = 0;
        int numb = 0;
        bool luckyNum = false;
        //Визначення сумми цифр обох половин:
        for (int i = 100000; i >= 1; i /= 10) {
                numb = num % (i * 10);
                numb /= i;
                if ( i > 100) {
                        sum1 += numb;
                }else{
                        sum2 += numb;
                }
        }
        //Перевірка на те, чи є число "щасливим":
        if (sum1 == sum2) {
                luckyNum = true;
        }else{
                luckyNum = false;
        }
        return (luckyNum);
}
