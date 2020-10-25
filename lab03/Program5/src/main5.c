int main() {
    const int number = 123 ; //Задане число
        float numer1 = number / 100 ; //Перша цифра числа
        float numer3 = number % 10 ; //Третя цифра числа
        float differ = (numer1 / numer3) ; //Обчислення того у скільки перше число більше за останнє
        int differ100I = differ * 100 ; //Різниця чисел домноженна на 100 і переведена в тип integer для відкинення дробної частини
        float differ100 = differ100I ; //Переведення числа від одного типу данних до іншого
        float result = differ100 / 100 ; //Округглення числа до двох цифр після коми
        return 0;
}
