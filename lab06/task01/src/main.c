//Центрувати заданий рядок із заданим заповнювачем
int main() {
        #define SIZE 15 //Розмір масиву
        char filler = '_' ; // Заповнювач
        char a[SIZE] = {'I','v','a','n','o','v',' ',' ',' ',' ',' ',' ',' ',' ','\0'} ; //Заданий масив
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
        return 0;
}
