//Заповнити масив із заданої кількості елементів простими числами що не повторюються
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int main() {
        srand(time(NULL));
        #define SIZE 100 //Розмір масиву
        int a[SIZE];//Заданий масив
        int num;
        int max = 100000;//Максимальне число для запису в масив
        //Цикл заповнення масиву випадковими натуральними числами які не повторюються
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
        return 0;
}

