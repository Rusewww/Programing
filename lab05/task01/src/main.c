int main () {
        const int a = 561 ;
        const int b = 143 ;
        int num1;
        int num2;
        if (a > b) {
                num1 = a;
                num2 = b;
        }else{
                num1 = b;
                num2 = a;
        }
        int remainder = 1;
        int divider ; 
        while (remainder > 0) {
                remainder = num1 % num2 ;
                num1 = num2 ;
                num2 = remainder ;
                if (remainder != 0) {
                divider = remainder ;
                }
        }
        return 0;
}                          
                
