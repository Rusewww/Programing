int main()
{
int number= 123;//Задане число
int num1=number/100;//Формула обчислення першої цифри заданного числа
int num2=number%100/10;//Формула обчислення другої цифри заданного числа
int num3=number%10;//Формула обчислення третьої цифри заданного числа
number= num3*100+num2*10+num1;//Число створене записуванням в обратному порядку цифр
 return 0;
}
