//Перевірте, чи є задане число простим.
int main() {
        const int num = 21 ; //Задане число.
        int primeNum = 1 ; //Якщо primeNum = 1, тоді число просте.
//Перевірка на одиницю(бо одиниця не є простим числом):
        if (num == 1) {
                primeNum = 0 ;
        }else if (num % 2 == 0){
                primeNum = 0 ;
        }else{
//Перевірка на те, чи є число простим:
                for (int i = 3; i < num; i+=2) {
                        if (num % i == 0) {
                                primeNum = 0 ;
                                break; 
                        }
                }
        }        
        return 0 ;
}
