int main() {
        const int num = 102300 ;
        int luckyNum = 0 ;
        int sum1 = 0;
        int sum2 = 0;
        int numb = 0;
        //int part1 = num / 1000 ;
        //int part2 = num % 1000 ;
        for (int i = 100000 ; i !=100 ; i = i / 10) {
                numb = num % (i * 10) ;
                numb = numb / i ;
                sum1 = sum1 + numb ;
                }
        for (int i = 100 ; i >= 1 ; i = i / 10) {
                numb = num % (i * 10) ;
                numb = numb / i ;
                sum2 = sum2 + numb ;
                }
        if (sum1 == sum2) {
                luckyNum = 1 ;
        }else{
                luckyNum = 0 ;
        }
        return 0;
}                
        
