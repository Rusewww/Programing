#include <stdbool.h>
int primeNum(int num) {
        bool primeNum = true;//Якщо primeNum = 1, тоді число просте.
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
int main () {
          const int num = 45;
          bool result = primeNum(num) ;
          return 0;
}
