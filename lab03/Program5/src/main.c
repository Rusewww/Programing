int main()
{
const int x=123;//Задане число
float x1= x/100;//Перша цифра числа
float x3= x%10;//Третя цифра числа
float a= (x1/x3);//Обчислення того у скільки перше число більше за останнє
int a2=a*100;//Різниця чисел домноженна на 100 і переведена в тип integer для відкинення дробної частини
float b=a2;//Переведення числа від одного типу данних до іншого
float y=b/100;//Округглення числа до двох цифр після коми
return 0;
}
