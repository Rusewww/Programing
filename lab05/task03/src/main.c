//Визначити, чи є ціле 6-значне число "щасливим"(числа в якому сумма цифр з першої половини дорівнює суммі чисел другої половини.
int main() {
        const int num = 102300 ; //Задане 6-значне число.
        int sum1 = 0 ;
        int sum2 = 0 ;
        int numb = 0 ;
        int luckyNum = 0 ; //Якщо luckyNum = 1, тоді число "щасливе".
//Визначення сумми цифр першої половини:
        for (int i = 100000; i !=100; i = i / 10) {
                numb = num % (i * 10) ;
                numb = numb / i ;
                sum1 = sum1 + numb ;
                }
//Визначення сумми цифр другої половини:
        for (int i = 100; i >= 1; i = i / 10) {
                numb = num % (i * 10) ;
                numb = numb / i ;
                sum2 = sum2 + numb ;
                }
//Перевірка на те, чи є число простим:
        if (sum1 == sum2) {
                luckyNum = 1 ;
        }else{
                luckyNum = 0 ;
        }
        return 0 ;
}                
        
