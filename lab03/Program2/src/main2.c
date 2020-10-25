int main() {
        const int numb = 123 ; //Задане число
        int numer1 = numb / 100 ; //Перша цифра числа
        int numer2 = numb % 100 / 10 ; //Друга цифра числа
        int numer3 = numb % 10 ; //Третя цифра числа
        int inverseNumb = numer3 * 100 + numer2 * 10 + numer1 ; //Обернене число
        return 0; 
}
