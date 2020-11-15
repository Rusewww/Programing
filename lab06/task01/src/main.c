int main() {
        #define SIZE 15 
        char filler = '_' ;
        char a[SIZE] = {'I','v','a','n','o','v',' ',' ',' ',' ',' ',' ',' ',' ','\0'} ;
        int namelength = 0;
        for (int i = 0; a[i] != '\0'; i++) {
                if (a[i] != ' ' ) {
                        namelength++;
                }
        }
        int fillersize = (SIZE - namelength) / 2 ;
        char copyA[SIZE];
        for (int i = 0; i <= SIZE; i++) {
                copyA[i] = a[i];
        }
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
