//Дано масив. Потрібно помножити його сам на себе по правилу множення матриць
#include <stdlib.h>
int main() {
        #define SIZE 3 //Розміри масивів
        int max = 10; //Максимальне значення числа яке буде занесено в масив
        int a[SIZE][SIZE]; //Заданий масив
        int sqA[SIZE][SIZE]; //Масив помножений на себе
        //Заповнення масиву випадковими числами
        for (int i = 0; i <= SIZE; i++) {
                for (int j = 0; j <= SIZE; j++)
                     a[i][j] = rand() % (max + 1);
        }
        //Алгоритм помноження масиву самого на себе
        for(int i = 0; i < SIZE; i++) {
                for(int j = 0; j < SIZE; j++) {
                        sqA[i][j] = 0;
                        for(int c = 0; c < SIZE; c++) {
                                sqA[i][j] += a[i][c] * a[c][j];
                        }
                }
        }
        return 0;
}
