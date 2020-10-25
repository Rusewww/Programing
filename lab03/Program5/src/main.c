int main() {
    const int number=123;//Задане число
    float firstNumeral=number/100;//Перша цифра числа
    float thirdNumeral=number%10;//Третя цифра числа
    float difference=(firstNumeral/thirdNumeral);//Обчислення того у скільки перше число більше за останнє
    int differenceMultiplied100=difference*100;//Різниця чисел домноженна на 100 і переведена в тип integer для відкинення дробної частини
    float differenceMultiplied100InFloat=differenceMultiplied100;//Переведення числа від одного типу данних до іншого
    float result=differenceMultiplied100InFloat/100;//Округглення числа до двох цифр після коми
    return 0;
}
