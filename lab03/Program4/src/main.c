int main()
{
int system=8;//Задана система числення
int a=1001;//Чотирирозрядне число в цій системі
int a1=a/1000;//Перша цифра числа
int a2=a%1000/100;//Друга цифра числа
int a3=a%100/10;//Третя цифра числа
int a4=a%10;//Четверта цифра числа
int aIn10=(a1*system*system*system)+(a2*system*system)+(a3*system)+a4;//Формула обчислення еквіваленту заданого числа в десятеричній системі
 return 0;
}
