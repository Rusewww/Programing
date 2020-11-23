/**
Функція main: задає заповнювач,строку та її розмір, і передає все до функції root.
*/
int main(){
        #define SIZE 15 //Розмір масиву
        char filler = '_' ; // Заповнювач
        char a[SIZE] = {'I','v','a','n','o','v',' ',' ',' ',' ',' ',' ',' ',' ','\0'} ;
        center(SIZE, a , filler);
        return 0;
}
/**
Функція center: центрує заданий рядок.
*/
void center(int SIZE, char a[], char filler) {
        int namelength = 0; //Довжина імені
        //Цикл для визначення довжини імені
        for (int i = 0; a[i] != '\0'; i++) {
                if (a[i] != ' ' ) {
                        namelength++;
                }
        }
        int fillersize = (SIZE - namelength) / 2 ; // Необхідна кількість заповнювача
        char copyA[SIZE];
        for (int i = 0; i <= SIZE; i++) {
                copyA[i] = a[i];
        }
        //Цикли центрування
        for (int i = fillersize; i < (SIZE - fillersize); i++) {
                a[i] = copyA[i - fillersize];
        }
        for (int i = 0; i < SIZE; i++) {
                if ( i < fillersize || a[i] == ' ' ) {
                        a[i] = filler;
                }
        }
}
