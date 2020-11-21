#include <stdbool.h>
int lucky(int num) {
        int sum1 = 0;
        int sum2 = 0;
        int numb = 0;
        bool luckyNum = false; //Якщо luckyNum = 1, тоді число "щасливе".
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
int main() {
        int num = 102111;
        bool result = lucky(num);
        return 0 ;
}
