//Дано масив. Виконати циклічне зміщення масиву справа на ліво
#include <stdlib.h>
#include <time.h>
int main() {
        srand(time(NULL));
        #define SIZE 3 //Розміри масиву
        int a[SIZE][SIZE];//Заданий масив
        int temp;
        int max = 10; //Максимальне значення числа яке буде в масиві
        //Заповнення масиву випадковими числами
        for (int i = 0; i <= SIZE; i++){
                for (int j = 0; j <= SIZE; j++)
                     a[i][j] = rand() % (max + 1);
        }
        //Алгоритм циклічного зміщення масиву вліво
        for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++) {
                        if (j == 0) {
                                temp = a[i][j];
                                
                        }else{
                                a[i][j - 1] = a[i][j];
                        }
                        if (j ==  (SIZE - 1)) {
                                a[i][j] = temp;
                        }
                }
        }
        return 0;
}   
