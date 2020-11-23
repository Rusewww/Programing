#include <stdarg.h>
/**
Функція first_more_that_second: визначає кількість пар цифр де перша більша за другу.
                                Перша цифра повинна вказувати на кількість цифр.
*/
int first_more_that_second(int n, ...) {
        int result = 0;
        int temp = 0;
        va_list factor;
        va_start (factor, n);
        for(int i=0;i <= n; i++) {
                if (va_arg(factor, int) < temp) {
                        result++;
                }
                temp = va_arg(factor,int);
        }
        va_end(factor);
        return (result);
}
/**
Функція main: задає цифри і їх кількість, і передає все до функції first_more_that_second.
*/
int main () {
        int result = first_more_that_second(10,19,17,10,-2,7,43,11,0,-10,44); //Результат
        return 0;
}
