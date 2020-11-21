#include <stdbool.h>
int perfect(int num) {
        int sum = 0;
        bool perfect; ////Якщо perfect = 1, тоді число досконале.
        //Розподіл числа на дільники, та визначення їх сумми:
        for (int i = 1; i <= num / 2; i++) {
                if (num % i == 0) {
                          sum += i;
                }
        }
        //Перевірка на те, чи є число досконалим:
        if (sum == num) {
                perfect = true;
        }else{
                perfect = false;
        }
        return (perfect);
}
int main() {
        int num = 6;
        bool result = perfect(num);
        return 0;
}
