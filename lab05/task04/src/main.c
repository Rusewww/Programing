int main() {
        const int num = 6 ;
        int copyNum = num ;
        int sum = 0 ;
        int perfect ;
        for (int i = 1 ; i < num ; i++) {
                if ( copyNum % i == 0) {
                          sum = sum + i;
                }
        }
        if (sum == num) {
                perfect = 1;
        }else{
                perfect = 0;
        }
        return 0;
}                
