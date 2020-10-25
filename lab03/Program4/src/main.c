int main() {
    const int system=8;//Задана система числення
    const int numberInSystem=1001;//Чотирирозрядне число в цій системі
    int firstNumeral=numberInSystem/1000;//Перша цифра числа
    int secondNumeral=numberInSystem%1000/100;//Друга цифра числа
    int thirdNumeral=numberInSystem%100/10;//Третя цифра числа
    int fourthNumeral=numberInSystem%10;//Четверта цифра числа
    int numberInDecimalSystem=(firstNumeral*system*system*system)+(secondNumeral*system*system)+(thirdNumeral*system)+fourthNumeral;//Формула обчислення еквіваленту заданого числа в десятеричній системі
    return 0;
}
