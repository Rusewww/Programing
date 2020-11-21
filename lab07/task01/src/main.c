int findGCF(int a, int b)
{
        int remainder = 1;
        int divider;
        int num1;
        int num2;
        if (a > b) {
                num1 = a;
                num2 = b;
        }else{
                num1 = b;
                num2 = a; 
        }
        while (remainder > 0) {
                remainder = num1 % num2;
                num1 = num2;
                num2 = remainder;
                if (remainder != 0) {
                        divider = remainder;
                }
        }
        return (divider);
}

int main() {
        int a = 45;
        int b = 30;
        int div;
        div = findGCF(b,a);
        return 0;
}

