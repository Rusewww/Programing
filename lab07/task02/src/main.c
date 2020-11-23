#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/**
Функція main: формує 1 випадкове число < 100, і передає його до функції prime_num.
*/
int main () {
        srand(time(NULL));
        int rand_max = 100;
        const int num = rand() % rand_max + 1;
        bool result = prime_num(num) ;
        return 0;
}
/**
Функція prime_num: Визначає являється подане число простим.
*/
int prime_num(int num) {
        bool primeNum = true;//
        //Перевірка на одиницю(бо одиниця не є простим числом):
        if (num == 1) {
                primeNum = false;
        }else if (num == 2){
                primeNum = true;
        }else if (num % 2 == 0){
                primeNum = false;
        }else{
        //Перевірка на те, чи є число простим:
               for (int i = 3; i < num; i += 2) {
                       if (num % i == 0) {
                               primeNum = false;
                               break;
                       }
               }
       }
       return (primeNum);
}
