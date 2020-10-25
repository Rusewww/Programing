int main() {
    const int number= 123;//Задане число
    int firstNumeral=number/100;//Формула обчислення першої цифри заданного числа
    int secondNumeral=number%100/10;//Формула обчислення другої цифри заданного числа
    int thirdNumeral=number%10;//Формула обчислення третьої цифри заданного числа
    int inverseNumber= thirdNumeral*100+secondNumeral*10+firstNumeral;//Число створене записуванням в обратному порядку цифр
    return 0;
}
