//Заповнити масив із заданої кількості елементів простими числами що не повторюються
#include <stdbool.h>
#include <stdlib.h>
int main() {
        #define SIZE 5 //Розмір масиву
        int a[SIZE];//Заданий масив
        int num;
        int max = 101;//Максимальне число для запису в масив
        //Цикл заповнення масиву випадковими натуральними числами
        for (int i = 0; i < SIZE; i++) {        
                bool primeNum;
                do {
                        num = rand() % max;
                        primeNum = true;
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
        return 0;
}

