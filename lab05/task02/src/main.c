int main() {
        const int num = 21 ;
        int primeNum = 1 ; //Якщо primeNum = 1, тоді число просте
        for (int i = 2 ; i < num; i++) {
                if (num % i == 0) {
                       primeNum = 0 ; 
                }
        }
        return 0 ;
}
