/**
 * @file main.c Завдання 1 лабораторної роботи №6.
 *
 * Центрувати заданий рядок із заданим заповнювачем.
 */

/**
 * @param filler - заповнювач;
 * @param a - массив з строкою;
 * @param SIZE - розмір масиву;
 */
static void center(int SSIZE, char a[], char filler);
/**
Функція main: задає заповнювач,строку та її розмір, і передає все до функції root.
*/
int main(){
        #define SIZE 15
        char filler = '_';
        char a[SIZE] = {'I','v','a','n','o','v',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
        center(SIZE, a, filler);
        return 0;
}
/**
Функція center: центрує заданий рядок.
*/
void center(int SSIZE, char a[], char filler) {
        int namelength = 0; //Довжина імені
        //Цикл для визначення довжини імені
        for (int i = 0; a[i] != '\0'; i++) {
                if (a[i] != ' ' ) {
                        namelength++;
                }
        }
        int fillersize = (SSIZE - namelength) / 2 ; // Необхідна кількість заповнювача
        char copyA[SSIZE];
        for (int i = 0; i <= SSIZE; i++) {
                copyA[i] = a[i];
        }
        //Цикли центрування
        for (int i = fillersize; i < (SSIZE - fillersize); i++) {
                a[i] = copyA[i - fillersize];
        }
        for (int i = 0; i < SSIZE; i++) {
                if ( i < fillersize || a[i] == ' ' ) {
                        a[i] = filler;
                }
        }
}
