#include <stdlib.h>
#include <time.h>
/**
Функція main: задає мансимальне значення числа для запису в масив, масив та його розміри,
              і заповнює його випадковими числами, і передає все до функції ROL_array.
*/
int main () {
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
        ROL_array(SIZE, a);
        return 0;
}
/**
Функція ROL_array: виконує циклічне зміщення масиву справа на ліво.
*/
void ROL_array(int SSIZE, int a[][SSIZE]) {
        int temp;
        //Алгоритм циклічного зміщення масиву вліво
        for (int i = 0; i < SSIZE; i++){
                for (int j = 0; j < SSIZE; j++) {
                        if (j == 0) {
                                temp = a[i][j];

                        }else{
                                a[i][j - 1] = a[i][j];
                        }
                        if (j ==  (SSIZE - 1)) {
                                a[i][j] = temp;
                        }
                }
        }
}
