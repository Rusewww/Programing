int main() {
        const int system = 8 ; //Задана система числення
        const int sysnumb = 1001 ; //Чотирирозрядне число в цій системі
        int numer1 = sysnumb / 1000 ; //Перша цифра числа
        int numer2 = sysnumb % 1000 / 100 ; //Друга цифра числа
        int numer3 = sysnumb % 100 / 10 ; //Третя цифра числа
        int numer4 = sysnumb % 10 ; //Четверта цифра числа
        int part1 = numer1 * system * system * system ; //Перша частина формули
        int part2 = numer2 * system * system ; //Друга частина формули
        int part3 = numer3 * system ; //Третя частина формули
        int sysNumb10 = part1 + part2 + part3 + numer4 ; //Число в 10-ричній системі
        return 0;
}
