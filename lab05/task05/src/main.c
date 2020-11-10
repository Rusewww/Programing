//Без допомоги зовнішніх бібліотек, отримати корінь заданого числа.
int main() {
        #define EPS 0.01 //Єпсілон точності
        const float num = 10;//Задане число
        float root = num /2 ;
        while (((root * root)- num)>= EPS || (num -(root * root))>= EPS ) {
                if (root * root > num) {
                        root -= root / 2;
                }else{
                        root += root / 2;  
                } 
        }   
        return 0;
}
