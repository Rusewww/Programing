int main() {
    const int number=2;//Число
    int numberIn2ndDegree=number*number;//Задане число в квадраті
    int numberIn4thDegree=numberIn2ndDegree*numberIn2ndDegree;//Задане число в четвертій степені(операції - строки 4 і 5)
    int numberIn6thDegree=numberIn4thDegree*numberIn2ndDegree;//Задане число в шостій степені(операції - строки 4, 5 і 6)
    int numberIn8thDegree=numberIn4thDegree*numberIn4thDegree;//Задане число в восьмій степені(операції - строки 4 ,5 і 7)
    int numberIn10thDegree=numberIn8thDegree*numberIn2ndDegree;//Задане число в десятій степені(операції - строки 4,5,7 і 8)
    return 0;
}
