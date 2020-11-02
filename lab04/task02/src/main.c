// Визначити у скількі разів значення дробової частини більше за значення цілої.
// Округлити результат до двох знаків після коми.
int main() {
        const float num = 123.456 ; // Задане число
        float fraction = num - (int)num ; // Обчислення дробової частини числа
        int flag = num ; // Копія заданого числа 
        int grade = 1 ; // Розрядність
        float difference ; // Різниця дробової та цілої частини
        // Визначення числа на яке потрібно домножити дробну частину
        while (flag != 0) {
                 grade *= 10 ;
                 flag /= 10 ; 
        }
        fraction *= grade ; // Домноження дробної частини
        if ((int)num != 0) {
                difference = fraction / (int)num ; // Різниця дробної та цілої частини 
        } else {
            difference = 0 ; // Рішення у випадку якщо ціла частина дорівнює нулю
        }  
        // Округлення числа до двох знаків після коми
        difference = difference * 100 ;
        difference = (int)difference ;
        difference /= 100 ; 
        return 0 ;
}
        
