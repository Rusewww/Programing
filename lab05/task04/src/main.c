//Визначте, чи є задане число досконалим (якщо воно дорівнює суммі воїх дільників).
int main() {
        const int num = 6 ; //Задане число.
        int copyNum = num ;
        int sum = 0 ;
        int perfect ; ////Якщо perfect = 1, тоді число досконале.
        //Розподіл числа на дільники, та визначення їх сумми:
        for (int i = 1; i < num; i++) {
                if ( copyNum % i == 0) {
                          sum = sum + i ;
                }
        }
        //Перевірка на те, чи є число досконалим:
        if (sum == num) {
                perfect = 1 ;
        }else{
                perfect = 0 ;
        } 
        return 0;
}                
