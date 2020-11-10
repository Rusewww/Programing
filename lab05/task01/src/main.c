//Визначити найбільший спільний дільник для двох заданих чисел.
int main () {
        const int a = 561;//Перше число
        const int b = 143;//Друге число
        int num1;
        int num2;
//Перестановка чисел від більшого до найменшого:
        if (a > b) {
                num1 = a;
                num2 = b;
        }else{
                num1 = b;
                num2 = a; 
        } 
        int remainder = 1;
        int divider;// Найбільший спільний дільник двох чисел.
//Знаходження НСД с допомогою алгоритму Євкліда:
        while (remainder > 0) {
                remainder = num1 % num2;
                num1 = num2;
                num2 = remainder;
                if (remainder != 0) {
                        divider = remainder;
                }
        }
        return 0 ;
}                          
                
